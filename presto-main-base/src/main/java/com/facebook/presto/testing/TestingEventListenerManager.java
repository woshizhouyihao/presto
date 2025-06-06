/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.facebook.presto.testing;

import com.facebook.presto.eventlistener.EventListenerConfig;
import com.facebook.presto.eventlistener.EventListenerManager;
import com.facebook.presto.spi.eventlistener.EventListener;
import com.facebook.presto.spi.eventlistener.EventListenerFactory;
import com.facebook.presto.spi.eventlistener.QueryCompletedEvent;
import com.facebook.presto.spi.eventlistener.QueryCreatedEvent;
import com.facebook.presto.spi.eventlistener.QueryProgressEvent;
import com.facebook.presto.spi.eventlistener.QueryUpdatedEvent;
import com.facebook.presto.spi.eventlistener.SplitCompletedEvent;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.inject.Inject;

import java.util.List;
import java.util.concurrent.atomic.AtomicReference;

public class TestingEventListenerManager
        extends EventListenerManager
{
    private final AtomicReference<List<EventListener>> configuredEventListeners = new AtomicReference<>(ImmutableList.of());

    @Inject
    public TestingEventListenerManager(EventListenerConfig config)
    {
        super(config);
    }

    @Override
    public void addEventListenerFactory(EventListenerFactory eventListenerFactory)
    {
        configuredEventListeners.set(ImmutableList.of(eventListenerFactory.create(ImmutableMap.of())));
    }

    @Override
    public void queryCompleted(QueryCompletedEvent queryCompletedEvent)
    {
        configuredEventListeners.get()
                .forEach(eventListener -> eventListener.queryCompleted(queryCompletedEvent));
    }

    @Override
    public void queryCreated(QueryCreatedEvent queryCreatedEvent)
    {
        configuredEventListeners.get()
                .forEach(eventListener -> eventListener.queryCreated(queryCreatedEvent));
    }

    @Override
    public void queryUpdated(QueryUpdatedEvent queryUpdatedEvent)
    {
        configuredEventListeners.get()
                .forEach(eventListener -> eventListener.queryUpdated(queryUpdatedEvent));
    }

    @Override
    public void publishQueryProgress(QueryProgressEvent queryProgressEvent)
    {
        configuredEventListeners.get()
                .forEach(eventListener -> eventListener.publishQueryProgress(queryProgressEvent));
    }

    @Override
    public void splitCompleted(SplitCompletedEvent splitCompletedEvent)
    {
        configuredEventListeners.get()
                .forEach(eventListener -> eventListener.splitCompleted(splitCompletedEvent));
    }

    public List<EventListener> getEventListeners()
    {
        return configuredEventListeners.get();
    }
}

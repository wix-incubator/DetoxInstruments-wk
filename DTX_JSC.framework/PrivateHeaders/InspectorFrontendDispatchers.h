/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 * Copyright (C) 2013-2016 Apple Inc. All rights reserved.
 * Copyright (C) 2014 University of Washington. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

// DO NOT EDIT THIS FILE. It is automatically generated from CombinedDomains.json
// by the script: Source/JavaScriptCore/inspector/scripts/generate-inspector-protocol-bindings.py

#pragma once

#include "InspectorProtocolObjects.h"
#include <inspector/InspectorValues.h>
#include <wtf/text/WTFString.h>

namespace Inspector {

class FrontendRouter;

class JS_EXPORT_PRIVATE ApplicationCacheFrontendDispatcher {
public:
    ApplicationCacheFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void applicationCacheStatusUpdated(const Inspector::Protocol::Network::FrameId& frameId, const String& manifestURL, int status);
    void networkStateUpdated(bool isNowOnline);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE CSSFrontendDispatcher {
public:
    CSSFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void mediaQueryResultChanged();
    void styleSheetChanged(const Inspector::Protocol::CSS::StyleSheetId& styleSheetId);
    void styleSheetAdded(RefPtr<Inspector::Protocol::CSS::CSSStyleSheetHeader> header);
    void styleSheetRemoved(const Inspector::Protocol::CSS::StyleSheetId& styleSheetId);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE CanvasFrontendDispatcher {
public:
    CanvasFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void canvasAdded(RefPtr<Inspector::Protocol::Canvas::Canvas> canvas);
    void canvasRemoved(const Inspector::Protocol::Canvas::CanvasId& canvasId);
    void canvasMemoryChanged(const Inspector::Protocol::Canvas::CanvasId& canvasId, double memoryCost);
    void cssCanvasClientNodesChanged(const Inspector::Protocol::Canvas::CanvasId& canvasId);
    void recordingFinished(const Inspector::Protocol::Canvas::CanvasId& canvasId, RefPtr<Inspector::Protocol::Recording::Recording> recording);
    void programCreated(const Inspector::Protocol::Canvas::CanvasId& canvasId, const Inspector::Protocol::Canvas::ProgramId& programId);
    void programDeleted(const Inspector::Protocol::Canvas::ProgramId& programId);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE ConsoleFrontendDispatcher {
public:
    ConsoleFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void messageAdded(RefPtr<Inspector::Protocol::Console::ConsoleMessage> message);
    void messageRepeatCountUpdated(int count);
    void messagesCleared();
    void heapSnapshot(double timestamp, const Inspector::Protocol::Heap::HeapSnapshotData& snapshotData, const String* const title);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE DOMFrontendDispatcher {
public:
    DOMFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void documentUpdated();
    void inspect(int nodeId);
    void setChildNodes(int parentId, RefPtr<Inspector::Protocol::Array<Inspector::Protocol::DOM::Node>> nodes);
    void attributeModified(int nodeId, const String& name, const String& value);
    void attributeRemoved(int nodeId, const String& name);
    void inlineStyleInvalidated(RefPtr<Inspector::Protocol::Array<Inspector::Protocol::DOM::NodeId>> nodeIds);
    void characterDataModified(int nodeId, const String& characterData);
    void childNodeCountUpdated(int nodeId, int childNodeCount);
    void childNodeInserted(int parentNodeId, int previousNodeId, RefPtr<Inspector::Protocol::DOM::Node> node);
    void childNodeRemoved(int parentNodeId, int nodeId);
    void shadowRootPushed(int hostId, RefPtr<Inspector::Protocol::DOM::Node> root);
    void shadowRootPopped(int hostId, int rootId);
        // Named after parameter 'customElementState' while generating command/event customElementStateChanged.
        enum class CustomElementState {
            Builtin = 53,
            Custom = 54,
            Waiting = 55,
            Failed = 56,
        }; // enum class CustomElementState
    void customElementStateChanged(int nodeId, Inspector::Protocol::DOM::CustomElementState customElementState);
    void pseudoElementAdded(int parentId, RefPtr<Inspector::Protocol::DOM::Node> pseudoElement);
    void pseudoElementRemoved(int parentId, int pseudoElementId);
    void didAddEventListener(int nodeId);
    void willRemoveEventListener(int nodeId);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE DOMStorageFrontendDispatcher {
public:
    DOMStorageFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void domStorageItemsCleared(RefPtr<Inspector::Protocol::DOMStorage::StorageId> storageId);
    void domStorageItemRemoved(RefPtr<Inspector::Protocol::DOMStorage::StorageId> storageId, const String& key);
    void domStorageItemAdded(RefPtr<Inspector::Protocol::DOMStorage::StorageId> storageId, const String& key, const String& newValue);
    void domStorageItemUpdated(RefPtr<Inspector::Protocol::DOMStorage::StorageId> storageId, const String& key, const String& oldValue, const String& newValue);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE DatabaseFrontendDispatcher {
public:
    DatabaseFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void addDatabase(RefPtr<Inspector::Protocol::Database::Database> database);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE DebuggerFrontendDispatcher {
public:
    DebuggerFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void globalObjectCleared();
    void scriptParsed(const Inspector::Protocol::Debugger::ScriptId& scriptId, const String& url, int startLine, int startColumn, int endLine, int endColumn, const bool* const isContentScript, const String* const sourceURL, const String* const sourceMapURL, const bool* const module);
    void scriptFailedToParse(const String& url, const String& scriptSource, int startLine, int errorLine, const String& errorMessage);
    void breakpointResolved(const Inspector::Protocol::Debugger::BreakpointId& breakpointId, RefPtr<Inspector::Protocol::Debugger::Location> location);
        // Named after parameter 'reason' while generating command/event paused.
        enum class Reason {
            XHR = 105,
            DOM = 162,
            EventListener = 163,
            Exception = 164,
            Assert = 45,
            CSPViolation = 165,
            DebuggerStatement = 166,
            Breakpoint = 167,
            PauseOnNextStatement = 168,
            Other = 30,
        }; // enum class Reason
    void paused(RefPtr<Inspector::Protocol::Array<Inspector::Protocol::Debugger::CallFrame>> callFrames, Reason reason, RefPtr<Inspector::InspectorObject> data, RefPtr<Inspector::Protocol::Console::StackTrace> asyncStackTrace);
    void resumed();
    void didSampleProbe(RefPtr<Inspector::Protocol::Debugger::ProbeSample> sample);
    void playBreakpointActionSound(int breakpointActionId);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE HeapFrontendDispatcher {
public:
    HeapFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void garbageCollected(RefPtr<Inspector::Protocol::Heap::GarbageCollection> collection);
    void trackingStart(double timestamp, const Inspector::Protocol::Heap::HeapSnapshotData& snapshotData);
    void trackingComplete(double timestamp, const Inspector::Protocol::Heap::HeapSnapshotData& snapshotData);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE InspectorFrontendDispatcher {
public:
    InspectorFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void evaluateForTestInFrontend(const String& script);
    void inspect(RefPtr<Inspector::Protocol::Runtime::RemoteObject> object, RefPtr<Inspector::InspectorObject> hints);
    void activateExtraDomains(RefPtr<Inspector::Protocol::Array<String>> domains);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE LayerTreeFrontendDispatcher {
public:
    LayerTreeFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void layerTreeDidChange();
private:
    FrontendRouter& m_frontendRouter;
};

#if ENABLE(RESOURCE_USAGE)
class JS_EXPORT_PRIVATE MemoryFrontendDispatcher {
public:
    MemoryFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
        // Named after parameter 'severity' while generating command/event memoryPressure.
        enum class Severity {
            Critical = 169,
            NonCritical = 170,
        }; // enum class Severity
    void memoryPressure(double timestamp, Severity severity);
    void trackingStart(double timestamp);
    void trackingUpdate(RefPtr<Inspector::Protocol::Memory::Event> event);
    void trackingComplete();
private:
    FrontendRouter& m_frontendRouter;
};
#endif // ENABLE(RESOURCE_USAGE)

class JS_EXPORT_PRIVATE NetworkFrontendDispatcher {
public:
    NetworkFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
        // Named after parameter 'type' while generating command/event requestWillBeSent.
        enum class Type {
            Document = 100,
            Stylesheet = 101,
            Image = 102,
            Font = 103,
            Script = 104,
            XHR = 105,
            Fetch = 106,
            Ping = 107,
            Beacon = 108,
            WebSocket = 109,
            Other = 110,
        }; // enum class Type
    void requestWillBeSent(const Inspector::Protocol::Network::RequestId& requestId, const Inspector::Protocol::Network::FrameId& frameId, const Inspector::Protocol::Network::LoaderId& loaderId, const String& documentURL, RefPtr<Inspector::Protocol::Network::Request> request, double timestamp, double walltime, RefPtr<Inspector::Protocol::Network::Initiator> initiator, RefPtr<Inspector::Protocol::Network::Response> redirectResponse, Inspector::Protocol::Page::ResourceType* type, const String* const targetId);
    void responseReceived(const Inspector::Protocol::Network::RequestId& requestId, const Inspector::Protocol::Network::FrameId& frameId, const Inspector::Protocol::Network::LoaderId& loaderId, double timestamp, Inspector::Protocol::Page::ResourceType type, RefPtr<Inspector::Protocol::Network::Response> response);
    void dataReceived(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, int dataLength, int encodedDataLength);
    void loadingFinished(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, const String* const sourceMapURL, RefPtr<Inspector::Protocol::Network::Metrics> metrics);
    void loadingFailed(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, const String& errorText, const bool* const canceled);
    void requestServedFromMemoryCache(const Inspector::Protocol::Network::RequestId& requestId, const Inspector::Protocol::Network::FrameId& frameId, const Inspector::Protocol::Network::LoaderId& loaderId, const String& documentURL, double timestamp, RefPtr<Inspector::Protocol::Network::Initiator> initiator, RefPtr<Inspector::Protocol::Network::CachedResource> resource);
    void webSocketWillSendHandshakeRequest(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, double walltime, RefPtr<Inspector::Protocol::Network::WebSocketRequest> request);
    void webSocketHandshakeResponseReceived(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, RefPtr<Inspector::Protocol::Network::WebSocketResponse> response);
    void webSocketCreated(const Inspector::Protocol::Network::RequestId& requestId, const String& url);
    void webSocketClosed(const Inspector::Protocol::Network::RequestId& requestId, double timestamp);
    void webSocketFrameReceived(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, RefPtr<Inspector::Protocol::Network::WebSocketFrame> response);
    void webSocketFrameError(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, const String& errorMessage);
    void webSocketFrameSent(const Inspector::Protocol::Network::RequestId& requestId, double timestamp, RefPtr<Inspector::Protocol::Network::WebSocketFrame> response);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE PageFrontendDispatcher {
public:
    PageFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void domContentEventFired(double timestamp);
    void loadEventFired(double timestamp);
    void frameNavigated(RefPtr<Inspector::Protocol::Page::Frame> frame);
    void frameDetached(const Inspector::Protocol::Network::FrameId& frameId);
    void frameStartedLoading(const Inspector::Protocol::Network::FrameId& frameId);
    void frameStoppedLoading(const Inspector::Protocol::Network::FrameId& frameId);
    void frameScheduledNavigation(const Inspector::Protocol::Network::FrameId& frameId, double delay);
    void frameClearedScheduledNavigation(const Inspector::Protocol::Network::FrameId& frameId);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE RuntimeFrontendDispatcher {
public:
    RuntimeFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void executionContextCreated(RefPtr<Inspector::Protocol::Runtime::ExecutionContextDescription> context);
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE ScriptProfilerFrontendDispatcher {
public:
    ScriptProfilerFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void trackingStart(double timestamp);
    void trackingUpdate(RefPtr<Inspector::Protocol::ScriptProfiler::Event> event);
    void trackingComplete(RefPtr<Inspector::Protocol::ScriptProfiler::Samples> samples);
    void programmaticCaptureStarted();
    void programmaticCaptureStopped();
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE TimelineFrontendDispatcher {
public:
    TimelineFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void eventRecorded(RefPtr<Inspector::Protocol::Timeline::TimelineEvent> record);
    void recordingStarted(double startTime);
    void recordingStopped(double endTime);
    void autoCaptureStarted();
    void programmaticCaptureStarted();
    void programmaticCaptureStopped();
private:
    FrontendRouter& m_frontendRouter;
};

class JS_EXPORT_PRIVATE WorkerFrontendDispatcher {
public:
    WorkerFrontendDispatcher(FrontendRouter& frontendRouter) : m_frontendRouter(frontendRouter) { }
    void workerCreated(const String& workerId, const String& url);
    void workerTerminated(const String& workerId);
    void dispatchMessageFromWorker(const String& workerId, const String& message);
private:
    FrontendRouter& m_frontendRouter;
};

} // namespace Inspector

/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include <utils/String8.h>

#include <EGL/egl.h>
#include <gui/Surface.h>


namespace android {

class EGLTest : public ::testing::Test {
protected:
    EGLDisplay mEglDisplay;

protected:
    EGLTest() {}
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(EGLTest, eglInitialize) {
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    ALOGE("eglGetDisplay returns %p\n", mEglDisplay);
    ASSERT_NE(EGL_NO_DISPLAY, display);
    ASSERT_EQ(EGL_SUCCESS, eglGetError());

    EGLint major = 0, minor = 0;
    EGLBoolean rc = eglInitialize(display, &major, &minor);
    printf("eglInitialize returns %i\n", rc);
    ASSERT_EQ(EGL_SUCCESS, eglGetError());

    sleep(10);
}
}

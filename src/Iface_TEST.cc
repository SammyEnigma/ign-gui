/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
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
 *
*/

#include <gtest/gtest.h>

#include "ignition/gui/Iface.hh"

using namespace ignition;
using namespace gui;

/////////////////////////////////////////////////
TEST(IfaceTest, MainWindowNoPlugins)
{
  EXPECT_TRUE(initApp());
  EXPECT_TRUE(createMainWindow());

  auto win = mainWindow();
  EXPECT_TRUE(win != nullptr);

  // Close window after 1 second
  QTimer::singleShot(1000, win, SLOT(close()));

  // Show window
  EXPECT_TRUE(runMainWindow());

  EXPECT_TRUE(stop());
}

/////////////////////////////////////////////////
TEST(IfaceTest, Dialog)
{
  EXPECT_TRUE(initApp());
  EXPECT_TRUE(loadPlugin("libImageDisplay.so"));
  EXPECT_TRUE(runDialogs());

  auto ds = dialogs();
  EXPECT_EQ(ds.size(), 1u);

  EXPECT_TRUE(stop());
}

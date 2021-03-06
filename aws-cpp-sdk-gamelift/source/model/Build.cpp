/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/gamelift/model/Build.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::GameLift::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Build::Build() : 
    m_buildIdHasBeenSet(false),
    m_nameHasBeenSet(false),
    m_versionHasBeenSet(false),
    m_statusHasBeenSet(false),
    m_sizeOnDisk(0),
    m_sizeOnDiskHasBeenSet(false),
    m_creationTimeHasBeenSet(false)
{
}

Build::Build(const JsonValue& jsonValue) : 
    m_buildIdHasBeenSet(false),
    m_nameHasBeenSet(false),
    m_versionHasBeenSet(false),
    m_statusHasBeenSet(false),
    m_sizeOnDisk(0),
    m_sizeOnDiskHasBeenSet(false),
    m_creationTimeHasBeenSet(false)
{
  *this = jsonValue;
}

Build& Build::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("BuildId"))
  {
    m_buildId = jsonValue.GetString("BuildId");

    m_buildIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Version"))
  {
    m_version = jsonValue.GetString("Version");

    m_versionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Status"))
  {
    m_status = BuildStatusMapper::GetBuildStatusForName(jsonValue.GetString("Status"));

    m_statusHasBeenSet = true;
  }

  if(jsonValue.ValueExists("SizeOnDisk"))
  {
    m_sizeOnDisk = jsonValue.GetInt64("SizeOnDisk");

    m_sizeOnDiskHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CreationTime"))
  {
    m_creationTime = jsonValue.GetDouble("CreationTime");

    m_creationTimeHasBeenSet = true;
  }

  return *this;
}

JsonValue Build::Jsonize() const
{
  JsonValue payload;

  if(m_buildIdHasBeenSet)
  {
   payload.WithString("BuildId", m_buildId);

  }

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", m_name);

  }

  if(m_versionHasBeenSet)
  {
   payload.WithString("Version", m_version);

  }

  if(m_statusHasBeenSet)
  {
   payload.WithString("Status", BuildStatusMapper::GetNameForBuildStatus(m_status));
  }

  if(m_sizeOnDiskHasBeenSet)
  {
   payload.WithInt64("SizeOnDisk", m_sizeOnDisk);

  }

  if(m_creationTimeHasBeenSet)
  {
   payload.WithDouble("CreationTime", m_creationTime.SecondsWithMSPrecision());
  }

  return payload;
}
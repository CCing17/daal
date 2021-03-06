/* file: em_gmm_covariance_storage_id.h */
/*******************************************************************************
* Copyright 2014-2017 Intel Corporation
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
*******************************************************************************/

/*
//++
//  the EM for GMM CovarianceStorageId class.
//--
*/

#ifndef __EM_GMM_COVARIANCE_STORAGE_ID_H__
#define __EM_GMM_COVARIANCE_STORAGE_ID_H__

#include "algorithms/algorithm.h"
#include "data_management/data/numeric_table.h"
#include "data_management/data/homogen_numeric_table.h"
#include "services/daal_defines.h"

namespace daal
{
namespace algorithms
{
namespace em_gmm
{

/**
 * @ingroup em_gmm
 * @{
 */
/**
 * <a name="DAAL-ENUM-ALGORITHMS__EM_GMM__COVARIANCESTORAGEID"></a>
 * Available identifiers of covariance types in the EM for GMM algorithm
 */
enum CovarianceStorageId
{
    full = 0,
    diagonal = 1
};

/** @} */

} // namespace em_gmm
} // namespace algorithm
} // namespace daal
#endif

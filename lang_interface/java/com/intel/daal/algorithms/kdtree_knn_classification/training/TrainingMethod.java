/* file: TrainingMethod.java */
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

/**
 * @defgroup kdtree_knn_classification_training Training
 * @brief Contains a class for KD-tree based kNN model-based training
 * @ingroup kdtree_knn_classification
 * @{
 */
package com.intel.daal.algorithms.kdtree_knn_classification.training;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__KDTREE_KNN_CLASSIFICATION__TRAINING__TRAININGMETHOD"></a>
 * @brief Available methods for k nearest neighbors model-based training
 */
public final class TrainingMethod {

    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    private int _value;

/** Default constructor */
    public TrainingMethod(int value) {
        _value = value;
    }

    /**
     * Returns a value corresponding to the identifier of the input object
     * \return Value corresponding to the identifier
     */

    public int getValue() {
        return _value;
    }

    private static final int defaultDenseValue = 0;

    public static final TrainingMethod defaultDense = new TrainingMethod(defaultDenseValue);   /*!< Default method */
}
/** @} */

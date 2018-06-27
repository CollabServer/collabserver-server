#pragma once

#include <cassert>

#include "collabdata/custom/SimpleGraph.h"

namespace collab {


/**
 * List all supported data for this server.
 */
enum class DataAvailable : int {
    DEFAULT_DATA = 1,
    SIMPLE_GRAPH
};


/**
 * Factory to create any collab data supported by the server.
 *
 * \date    June 2018
 * \author  Constantin Masson
 */
class DataFactory {
    private:
        DataFactory() = delete;

    public:

        /**
         * Create a new CollabData according to given ID.
         * Data is created on the head (new).
         * You must release the memory later.
         *
         * \param id The ID of CollabData to create.
         * \return Pointer to the created data or nullptr if error.
         */
        static CollabData* newDataByID(const DataAvailable id) {
            switch(id) {
                case DataAvailable::DEFAULT_DATA:
                case DataAvailable::SIMPLE_GRAPH:
                    return new SimpleGraph();

                default:
                    return nullptr;
            }
        }

        /**
         * Release the memory used by data.
         * This basically free the data pointer, don't use it anymore.
         *
         * \param data CollabData pointer to free.
         */
        static void releaseData(CollabData* data) {
            assert(data != nullptr);
            if(data != nullptr) {
                delete data;
            }
        }
};


} // End namespace


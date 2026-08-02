#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace open3D {
    class baseTransformStruct {

    public:
        struct TransformData {

            glm::vec3 localPosition;
            glm::quat localRotation;
            glm::vec3 localScale;

            int parentIndex = -1;
            int childIndex = 0;
            std::vector<int> children;

            glm::mat4 worldMatrix = glm::mat4(1.0f);

            bool isDirty = true;
            bool isStatic = false;
        };

        struct RenderSpaces {
            glm::mat4 modelMatrix = glm::mat4(1.0f);
            glm::mat4 viewMatrix = glm::mat4(1.0f);
            glm::mat4 projectionMatrix = glm::mat4(1.0f);
        };

        TransformData transform_data;
        RenderSpaces render_data;

    };
}
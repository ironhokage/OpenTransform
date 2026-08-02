#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include "baseTransformStruct.h"

namespace open3D {
    class Camera {
    public:
        [[nodiscard]] inline glm::mat4 GetViewMatrix();

        inline void CamMoveForward();
        inline void CamMoveBackward();
        inline void CamMoveLeft();
        inline void CamMoveRight();

    private:
        glm::vec3 mCamEye;
        glm::vec3 mViewDir;
        glm::vec3 mUpVec;

        baseTransformStruct data;
    };

    // This returns the view matrix needed for the MVP matrix to work
    inline glm::mat4 Camera::GetViewMatrix() {
        data.render_data.viewMatrix = glm::lookAt(mCamEye, mViewDir, mUpVec);
        return data.render_data.viewMatrix;
    }

    inline void Camera::CamMoveForward() {
    }

    inline void Camera::CamMoveBackward() {
    }

    inline void Camera::CamMoveLeft() {
    }

    inline void Camera::CamMoveRight() {
    }
}

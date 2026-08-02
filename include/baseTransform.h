#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "baseTransformStruct.h"

namespace open3D {

   class baseTransform {
   public:
        baseTransformStruct data;

      inline void ComputeObjCoord(float fov, float screenWidth, float screenHeight, float nearPlane, float farPlane);
      [[nodiscard]] inline glm::mat4 ComputeMVPMatrix() const;
   };

   inline void baseTransform::ComputeObjCoord(float fov, float screenWidth, float screenHeight, float nearPlane, float farPlane){

       const glm::mat4 localPositionMatrix = glm::translate(glm::mat4(1.0f), data.transform_data.localPosition);
       const glm::mat4 localScaleMatrix = glm::scale(glm::mat4(1.0f), data.transform_data.localScale);
       const glm::mat4 localRotationMatrix = glm::mat4_cast(data.transform_data.localRotation);

       //This is the TRS multiplication, T being the translate or localPositionMatrix,
       //R being rotate or localRotationMatrix and S being scale or localScaleMatrix
       data.render_data.modelMatrix = localPositionMatrix * localRotationMatrix * localScaleMatrix;
       data.render_data.projectionMatrix = glm::perspective(glm::radians(fov), screenWidth/screenHeight, nearPlane, farPlane);
   }

   inline glm::mat4 baseTransform::ComputeMVPMatrix() const {
         return data.render_data.projectionMatrix * data.render_data.viewMatrix * data.render_data.modelMatrix ;
   }
}




#ifndef RIGETBODY_H
#define RIGETBODY_H

#include "Vector2D.h"

#define UNI_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1

class RigetBody
{
    public:
        RigetBody() {
            m_Mass = UNI_MASS;
            m_Gravity = GRAVITY;
        }
        // ����� � ��������� (������)
        inline void SetMass(float mass){m_Mass = mass;}
        inline void SetGravity(float gravity){m_Gravity = gravity;}

        // ������ ���� �������� ��� ������� ��.����
        inline void ApplyForce(Vector2D F){m_Force = F;}
        inline void ApplyForceX(float Fx){m_Force.X = Fx;}
        inline void ApplyForceY(float Fy){m_Force.Y = Fy;}
        inline void UnSetForce(){m_Force = Vector2D(0,0);}

        //�����
        inline void ApplyFriction(Vector2D Fr){m_Friction = Fr;}
        inline void UnSetFriction(){m_Friction = Vector2D(0,0);}

        //������
        inline float GetMass(){return m_Mass;}
        inline Vector2D GetPosition(){return m_Position;}
        inline Vector2D GetVeclocity(){return m_Velocity;}
        inline Vector2D GetAcceleration(){return m_Accelaration;}

        //
        void Update(float dt){
            m_Accelaration.X = (m_Force.X + m_Friction.X)/m_Mass;
            m_Accelaration.Y = m_Gravity + m_Force.Y/m_Mass;
            m_Velocity = m_Accelaration*dt;
            m_Position = m_Velocity*dt;
        }
    private:
        float m_Mass;
        float m_Gravity;

        Vector2D m_Force;
        Vector2D m_Friction;

        Vector2D m_Position;
        Vector2D m_Velocity;
        Vector2D m_Accelaration;


};

#endif // RIGETBODY_H

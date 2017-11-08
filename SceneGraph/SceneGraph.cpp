// SceneGraph.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
using Mesh = int;
using Vector = std::array<double, 3>;
using Quaternion = std::array<double, 4>;

Vector somePos;
Quaternion someRot;

// This is a third party API, somewhat similar in style to OpenGL
using Scene = void*;

void init(Scene *result);
void addMeshToScene(Scene s, std::string const & Mesh);
void beginOffset(Scene s, Vector pos, Quaternion rot);
void endOffset(Scene s);
void draw(Scene s);

#if 1 // Fake implementation

void init(Scene * result)
{
}

void addMeshToScene(Scene s, std::string const & Mesh)
{
}

void beginOffset(Scene s, Vector pos, Quaternion rot)
{
}

void endOffset(Scene s)
{
}

void draw(Scene s)
{
}
#endif


int main()
{
    Scene scene;
    init(&scene);
    addMeshToScene(scene, "landscape");
    beginOffset(scene, somePos, someRot);
        addMeshToScene(scene, "tank");
        addMeshToScene(scene, "registrationPlate123");
        beginOffset(scene, somePos, someRot);
            addMeshToScene(scene, "turret");
            beginOffset(scene, Vector{}, someRot);
                addMeshToScene(scene, "canon");
            endOffset(scene);
            beginOffset(scene, Vector{}, someRot);
                addMeshToScene(scene, "shooter");
                endOffset(scene);
            endOffset(scene);
        endOffset(scene);
    endOffset(scene);
    
    draw(scene);
    return 0;
}



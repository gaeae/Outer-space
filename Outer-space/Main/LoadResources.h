#pragma once

#include <string>
#include <windows.h>

static class LoadResources
{
public:
    // Images
    static std::string GetAsteriodLarge() { return resourceDir() + "Images\\asteroid.large.jpg"; }
    static std::string GetAsteroid() { return resourceDir() + "Images\\asteroid_new.png"; }
    static std::string GetAsteroidTarget() { return resourceDir() + "Images\\asteroid_new_target.png"; }
    static std::string GetBackground() { return resourceDir() + "Images\\background.jpg"; }
    static std::string GetButton() { return resourceDir() + "Images\\button.png"; }
    static std::string GetEnemy() { return resourceDir() + "Images\\enemy.png"; }
    static std::string GetExplosion1() { return resourceDir() + "Images\\explosion1.png"; }
    static std::string GetExplosion2() { return resourceDir() + "Images\\explosion2.png"; }
    static std::string GetHealth() { return resourceDir() + "Images\\health.png"; }
    static std::string GetMouse() { return resourceDir() + "Images\\mouse.png"; }
    static std::string GetMouse2() { return resourceDir() + "Images\\mouse2.png"; }
    static std::string GetMouseStinke() { return resourceDir() + "Images\\mousestinke.jpg"; }
    static std::string GetMouseHyper() { return resourceDir() + "Images\\mouse_hyper.jpeg"; }
    static std::string GetPlayer() { return resourceDir() + "Images\\player.jpg"; }
    static std::string GetPlayerRaw() { return resourceDir() + "Images\\player_raw.jpg"; }
    static std::string GetPlayer27() { return resourceDir() + "Images\\player27.jpg"; }
    static std::string GetShield() { return resourceDir() + "Images\\shield.png"; }
    static std::string GetShiedNew() { return resourceDir() + "Images\\shield_new.jpg"; }
    static std::string GetShot() { return resourceDir() + "Images\\shot.png"; }

    // Sounds
    static std::string GetExit() { return resourceDir() + "Sounds\\exit.wav"; }
    static std::string GetExplosion() { return resourceDir() + "Sounds\\explosion.wav"; }
    static std::string GetStart() { return resourceDir() + "Sounds\\start.wav"; }

    // Fonts
    static std::string GetFontArial() { return resourceDir() + "Fonts\\arial.ttf"; }

private:

    static std::string solutionDir()
    {
        //std::string SOLUTIONDIR = R"($(SolutionDir))";
        //return SOLUTIONDIR;

        char buf[256];
        GetCurrentDirectoryA(256, buf);
        return std::string(buf) + "\\..\\";
    }

    static std::string resourceDir()
    {
        return solutionDir() + "\\Resources\\";
    }


    static std::string getWorkingDir() { return R"($(SolutionDir))"; }
};
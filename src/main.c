#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
    #define NOGDI            
    #define NOUSER            
    #define WIN32_LEAN_AND_MEAN 
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "raylib.h"

#define ONE_HOUR 3600000


int main(){
    //config de como vai ser a janela
    do
    {
    Sleep((ONE_HOUR/2)/2); //30 min
        
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_MOUSE_PASSTHROUGH);
    InitWindow(350, 100, "ALERTA PARA TOMAR ÁGUA");
    InitAudioDevice();
    srand(time(NULL));

    int num_aleatorio = rand() % 2; //0 e 1
  
    //variaveis importantes sobre a tela e a janela
    int monitor = GetCurrentMonitor(); //0 
    int largura_tela = GetMonitorWidth(monitor); //1920 
    int altura_tela =  GetMonitorHeight(monitor); //1080

    int posicao_tela_x = largura_tela/2 + 580;
    int posicao_tela_y = altura_tela - 132;

    int posicao_janela_x = 350;
    int posicao_janela_y = 100;

    Sound plin = LoadSound("src/plin.wav");
    Sound fahh = LoadSound("src/Fahh.wav");

    Image icon = LoadImage("icon.png");

    //definição de como vai ficar a janela
    SetTargetFPS(60);
    SetWindowPosition(posicao_tela_x, posicao_tela_y);
    SetWindowOpacity(0.9f);
    SetSoundVolume(plin, 0.09f);
    SetSoundVolume(fahh, 0.1f);
    SetWindowIcon(icon);    

    double tempoInicial = GetTime();

    //loop principal
    while (!WindowShouldClose() && (GetTime() - tempoInicial) < 5.0)
    {
        float tempoRestante = 5.0f - (float)(GetTime() - tempoInicial);
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("TOME ÁGUA DE IMEDIATO", 47, posicao_janela_y - 67, 20, RED);
            DrawText(TextFormat("Tempo de autodestruição: %.1fs", tempoRestante), 47 , posicao_janela_y - 34, 15, RED);
            DrawRectangleLines(0,0,350,100,RED);
            
        EndDrawing();
    }
    if(num_aleatorio == 0){
       PlaySound(plin);
       WaitTime(0.05f);
    }
    else if (num_aleatorio == 1){
        PlaySound(fahh);
        WaitTime(0.05f);
    }
    
    while (IsSoundPlaying(plin) || IsSoundPlaying(fahh))
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("+Aura", 67, posicao_janela_y - 67, 67, RED);
        DrawRectangleLines(0,0,350,100,RED);
        EndDrawing();
    }
    UnloadSound(plin);
    UnloadSound(fahh);
    CloseAudioDevice();
    CloseWindow();
    }while (1);
    return 0;
}
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
/*for bg sound*/
#include <mmsystem.h>

/*to remove flicker*/
void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

int main() {
    system("color 4F");
    PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
    srand(time(0));
    
    // NEW: Game variables
    int score = 0;           // Score counter
    int lives = 3;           // Player lives
    int speed = 120;         // Game speed (decreases = faster)
    
    int x = 1;               // player position (0 to 2)
    int step = 0;            // obstacle vertical movement
    int obstaclePos = rand() % 3;   // 0,1,2 lane
    
    while (lives > 0) {      // Loop continues while player has lives
        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();
            if (ch == 'a' && x > 0)        // A key = left
               x--;
            if (ch == 'd' && x < 2)        // D key = right
               x++;
        }
        
        // ---- DRAW ----
        clear_screen_fast();
        
        // Display score and lives at top
        printf("SCORE: %d  |  LIVES: %d  |  SPEED: %d\n", score, lives, 120 - speed + 120);
        printf("|--- --- ---|\n");
        
        for (int i = 0; i < 10; i++) {
            if (i == step) {
                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);
                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);
                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);
            } else {
                printf("|           |\n");
            }
        }
        
        // ---- PLAYER ----
        if (x == 0)
            printf("| %c         |\n", 6);
        else if (x == 1)
            printf("|     %c     |\n", 6);
        else if (x == 2)
            printf("|        %c  |\n", 6);
        
        printf("|--- --- ---|\n");
        
        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos) {
            PlaySound(TEXT("impact.wav"), NULL, SND_ASYNC);
            lives--;  // Lose one life
            
            if (lives > 0) {
                printf("\nHIT! Lives remaining: %d\n", lives);
                Sleep(1500);
                // Reset obstacle position
                step = 0;
                obstaclePos = rand() % 3;
            } else {
                PlaySound(NULL, NULL, 0);  // stop background
                Sleep(2500);
                printf("\nGAME OVER!\n");
                printf("Final Score: %d\n", score);
                break;
            }
        }
        
        Sleep(speed);  // Use variable speed
        
        // Move obstacle down
        step++;
        
        // Reset when reaches bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3; // new lane
            score++;  // Increase score when obstacle is dodged
            
            // DIFFICULTY: Increase speed every 5 points
            if (score % 5 == 0 && speed > 50) {
                speed -= 10;  // Decrease delay = faster game
            }
        }
    }
    
    return 0;
}

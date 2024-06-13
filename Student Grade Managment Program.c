#include <stdio.h>
#include <string.h>
int main() {
    int numStudents; //numstudents-for total number of studentsnumsubjects- for total number of subjects
    int numSubjects;   
    // Getting the number of students and subjects form the user
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);   
    char names[numStudents][50];
    float scores[numStudents][numSubjects];
    float averages[numStudents];
    char highestStudent[50], lowestStudent[50];
    float highestScore = -1, lowestScore = 101;    
    // Getting students data from the user
    for (int i = 0; i < numStudents; i++) {
        printf("Enter the student's name: ");
        scanf("%s", names[i]);
        printf("Enter the scores for different subjects", numSubjects);
        for (int j = 0; j < numSubjects; j++) {
            scanf("%f", &scores[i][j]);
        }
    }    
    // calculating the average scores
    for (int i = 0; i < numStudents; i++) {
        float sum = 0;
        for (int j = 0; j < numSubjects; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / numSubjects;
    }    
    // Finding the lowest and highest scores and by whom
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            if (scores[i][j] > highestScore) {
                highestScore = scores[i][j];
                strcpy(highestStudent, names[i]);
            }
            if (scores[i][j] < lowestScore) {
                lowestScore = scores[i][j];
                strcpy(lowestStudent, names[i]);
            }
        }
    }    
    // Printing the summary
    printf("\nStudent Performance Summary:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student: %s, Scores: ", names[i]);
        for (int j = 0; j < numSubjects; j++) {
            printf("%.2f ", scores[i][j]);
        }
        printf(", Average: %.2f", averages[i]);        
        // Determining the category of student based on their scores
        if (averages[i] < 60) {
            printf(", Performance: Below Average\n");
        } else if (averages[i] <= 80) {
            printf(", Performance: Average\n");
        } else {
            printf(", Performance: Good\n");
        }
    }    
    // Printing the highest score
    printf("\nHighest score: %.2f\nby %s\n", highestScore, highestStudent);    
    // Printing the lowest score
    printf("Lowest score: %.2f\nby %s\n", lowestScore, lowestStudent);    
    return 0;
}

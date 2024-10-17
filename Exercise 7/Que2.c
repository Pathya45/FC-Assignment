#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 
void sortWord(char *word) { 
    int len = strlen(word); 
    for (int i = 0; i < len - 1; i++) { 
        for (int j = i + 1; j < len; j++) { 
            if (word[i] > word[j]) { 
             
                char temp = word[i]; 
                word[i] = word[j]; 
                word[j] = temp; 
            } 
        } 
    } 
} 
 

sentence 
void processSentence(char *sentence) { 
    char *word = strtok(sentence, " ");
    while (word != NULL) { 
        sortWord(word);                
        printf("%s ", word);          
        word = strtok(NULL, " ");      
    } 
} 
 
int main() { 
    char sentence[100]; 
 
   
    printf("Enter a sentence: "); 
    fgets(sentence, sizeof(sentence), stdin); 
 
   
    size_t len = strlen(sentence); 
    if (len > 0 && sentence[len - 1] == '\n') { 
        sentence[len - 1] = '\0'; 
    } 
 
  
    processSentence(sentence); 
 
    return 0; 
}
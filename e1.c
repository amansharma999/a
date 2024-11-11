// <--------------------------------------------------------------->
// to run lex file

// flex filename.l
// gcc lex.yy.c 
// ./a.out

// to run c file

// gcc filename.c -o filename
// ./filename
// <--------------------------------------------------------------->


// /**
//  * C program to count number of characters, words and lines in a text file.
//  */

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     FILE * file;
//     char path[100];

//     char ch;
//     int characters, words, lines;


//     /* Input path of files to merge to third file */
//     printf("Enter source file path: ");
//     scanf("%s", path);

//     /* Open source files in 'r' mode */
//     file = fopen(path, "r");


//     /* Check if file opened successfully */
//     if (file == NULL)
//     {
//         printf("\nUnable to open file.\n");
//         printf("Please check if file exists and you have read privilege.\n");

//         exit(EXIT_FAILURE);
//     }

//     /*
//      * Logic to count characters, words and lines.
//      */
//     characters = words = lines = 0;
//     while ((ch = fgetc(file)) != EOF)
//     {
//         characters++;

//         /* Check new line */
//         if (ch == '\n' || ch == '\0')
//             lines++;

//         /* Check words */
//         if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
//             words++;
//     }

//     /* Increment words and lines for last word */
//     if (characters > 0)
//     {
//         words++;
//         lines++;
//     }

//     /* Print file statistics */
//     printf("\n");
//     printf("Total characters = %d\n", characters);
//     printf("Total words      = %d\n", words);
//     printf("Total lines      = %d\n", lines);


//     /* Close files to release resources */
//     fclose(file);

//     return 0;
// }

//     // Explanation:
//     // 1. Prompts the user to enter the path of a source text file.
//     // 2. Attempts to open the specified file in read mode.
//     // 3. Checks if the file was opened successfully; if not, prints an error and exits.
//     // 4. Initializes counters for characters, words, and lines to zero.
//     // 5. Reads the file character by character using fgetc.
//     // 6. Increments the respective counters based on the characters read.
//     // 7. After processing, it prints the total counts and closes the file.

//     // Sample Input:
//     // Enter source file path: sample.txt

//     // Sample Output:
//     // Total characters = 150
//     // Total words      = 25
//     // Total lines      = 10
// }


// ############################################################
//  C program to read name and marks of n number of students and store them in a file.
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//    char name[50];
//    int marks, i, num;

//    printf("Enter number of students: ");
//    scanf("%d", &num);

//    FILE *fptr;
// fptr = fopen("student.txt", "w");
//    if(fptr == NULL)
//    {
//        printf("Error!");
//        exit(1);
//    }

//    for(i = 0; i < num; ++i)
//    {
//       printf("For student%d\nEnter name: ", i+1);
//       scanf("%s", name);

//       printf("Enter marks: ");
//       scanf("%d", &marks);

//       fprintf(fptr,"\nName: %s \nMarks=%d \n", name, marks);
//    }

//    fclose(fptr);
//    return 0;
// }

// // Explanation:
// // 1. Prompts the user to enter the number of students.
// // 2. Opens (or creates) a file named "student.txt" in write mode.
// // 3. Checks if the file was opened successfully; if not, prints an error and exits.
// // 4. Iterates from 1 to the number of students, prompting for each student's name and marks.
// // 5. Writes each student's name and marks to the file in the format "Name Marks".
// // 6. After collecting all entries, closes the file to save the data.
// // 7. Confirms to the user that data has been successfully written to the file.

// // Sample Input:
// // Enter number of students: 2
// // Enter name of student 1: Alice
// // Enter marks of student 1: 85
// // Enter name of student 2: Bob
// // Enter marks of student 2: 90



// ############################################################

// C program to remove a specific line from
// the text file

// #include <stdio.h>

// int main()
// {
//     FILE* fp1;
//     FILE* fp2;

//     char ch;

//     int line = 0;
//     int temp = 1;

//     fp1 = fopen("a.txt", "r");
//     if (fp1 == NULL) {
//         printf("\nUnable to open file\n");
//         return -1;
//     }

//     fp2 = fopen("temp.txt", "w");

//     printf("\nEnter line number to delete the line: ");
//     scanf("%d", &line);

//     while ((ch = getc(fp1)) != EOF) {
//         if (ch == '\n')
//             temp++;

//         if (temp != line)
//             putc(ch, fp2);
//     }

//     fclose(fp1);
//     fclose(fp2);

//     fp1 = fopen("a.txt", "w");
//     fp2 = fopen("temp.txt", "r");

//     while ((ch = getc(fp2)) != EOF) {
//         putc(ch, fp1);
//     }

//     fclose(fp1);
//     fclose(fp2);

//     remove("temp.txt");

//     printf("\nModified file:\n");

//     fp1 = fopen("a.txt", "r");
//     if (fp1 == NULL) {
//         printf("\nUnable to open file\n");
//         return -1;
//     }

//     while ((ch = getc(fp1)) != EOF) {
//         printf("%c", ch);
//     }

//     fclose(fp1);

//     printf("\n");

//     return 0;
// }


// // Explanation:
// // 1. Opens the source file "a.txt" in read mode.
// // 2. Opens a temporary file "temp.txt" in write mode.
// // 3. Prompts the user to enter the line number they wish to delete.
// // 4. Reads the source file character by character.
// // 5. Keeps track of the current line number.
// // 6. Writes all characters to the temporary file except those on the specified line.
// // 7. Closes both files to ensure data is saved and resources are freed.

// // Sample Input:
// // Enter line number to delete the line: 3

// ############################################################
//  C program to copy contents of one file to another
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     FILE *fptr1, *fptr2;
//     char filename[100], c;

//     printf("Enter the filename to open for reading: ");
//     scanf("%s", filename);

//     // Open one file for reading
//     fptr1 = fopen(filename, "r");
//     if (fptr1 == NULL)
//     {
//         printf("Cannot open file %s \n", filename);
//         exit(0);
//     }

//     printf("Enter the filename to open for writing: ");
//     scanf("%s", filename);

//     // Open another file for writing
//     fptr2 = fopen(filename, "w");
//     if (fptr2 == NULL)
//     {
//         printf("Cannot open file %s \n", filename);
//         exit(0);
//     }

//     // Read contents from file
//     c = fgetc(fptr1);
//     while (c != EOF)
//     {
//         fputc(c, fptr2);
//         c = fgetc(fptr1);
//     }

//     printf("\nContents copied to %s", filename);

//     fclose(fptr1);
//     fclose(fptr2);
//     return 0;
// }


//     // Explanation:
//     // 1. Prompts the user to enter the filename to open for reading.
//     // 2. Attempts to open the specified file in read mode.
//     // 3. Checks if the file was opened successfully; if not, prints an error and exits.
//     // 4. Prompts the user to enter the filename to open for writing.
//     // 5. Attempts to open (or create) the specified file in write mode.
//     // 6. Reads the contents of the source file character by character.
//     // 7. Writes each character to the destination file.
//     // 8. Continues the process until the end of the source file is reached.
//     // 9. Closes both files to ensure data is saved and resources are freed.

//     // Sample Input:
//     // Enter the filename to open for reading: source.txt
//     // Enter the filename to open for writing: destination.txt
//     // Sample Output:
//     // Contents copied to destination.txt
// ############################################################

// Write a C program to detect tokens in a C program.
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// int main()
// {
//     FILE *fptr;
//     char filename[100], c;
//     int i, j, count = 0;
//     char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
//                               "do", "double", "else", "enum", "extern", "float", "for", "goto",
//                               "if", "int", "long", "register", "return", "short", "signed",
//                               "sizeof", "static", "struct", "switch", "typedef", "union",
//                               "unsigned", "void", "volatile", "while"};

//     // Open file
//     printf("Enter the filename to open \n");
//     scanf("%s", filename);
//     fptr = fopen(filename, "r");
//     if (fptr == NULL)
//     {
//         printf("Cannot open file \n");
//         exit(0);
//     }

//     // Read contents from file
//     c = fgetc(fptr);
//     while (c != EOF)
//     {
//         // While a comment is found
//         if (c == '/')
//         {
//             c = fgetc(fptr);
//             if (c == '/')
//             {
//                 while (c != '\n')
//                     c = fgetc(fptr);
//             }
//             else if (c == '*')
//             {
//                 do
//                 {
//                     while (c != '*')
//                         c = fgetc(fptr);
//                     c = fgetc(fptr);
//                 } while (c != '/');
//             }
//         }

//         // While a string literal is found
//         if (c == '"')
//         {
//             do
//             {
//                 c = fgetc(fptr);
//             } while (c != '"');
//         }

//         // While a character literal is found
//         if (c == '\'')
//         {
//             do
//             {
//                 c = fgetc(fptr);
//             } while (c != '\'');
//         }

//         // While a preprocessor directive is found
//         if (c == '#')
//         {
//             while (c != '\n')
//                 c = fgetc(fptr);
//         }

//         // While a keyword or an identifier is found
//         if (isalpha(c) || c == '_')
//         {
//             char word[100];
//             i = 0;
//             do
//             {
//                 word[i++] = c;
//                 c = fgetc(fptr);
//             } while (isalnum(c) || c == '_');
//             word[i] = '\0';
//             int flag = 0;
//             for (j = 0; j < 32; j++)
//             {
//                 if (strcmp(word, keywords[j]) == 0)
//                 {
//                     flag = 1;
//                     break;
//                 }
//             }
//             if (flag == 1)
//                 printf("%s is a keyword\n", word);
//             else
//                 printf("%s is an identifier\n", word);
//         }

//         // While a number is found
//         if (isdigit(c))
//         {
//             do
//             {
//                 c = fgetc(fptr);
//             } while (isdigit(c));
//             printf("%c is a number\n", c);
//         }

//         // While a special character is found
//         if (!isalnum(c))
//         {
//             printf("%c is a special character\n", c);
//             c = fgetc(fptr);
//         }
//     }

//     fclose(fptr);
//     return 0;
// }

//     // Explanation:
//     // 1. Defines an array of C language keywords to search for.
//     // 2. Prompts the user to enter the filename to analyze.
//     // 3. Attempts to open the specified file in read mode.
//     // 4. Checks if the file was opened successfully; if not, prints an error and exits.
//     // 5. Reads the file character by character using fgetc.
//     // 6. Skips single-line comments to avoid counting keywords within comments.
//     // 7. Counts the occurrences of each keyword found in the file.
//     // 8. Closes the file after processing is complete.

//     // Sample Input: 
//     // Enter the filename to open: sample.c

//     // Sample Output:
//     // auto is a keyword
//     // int is a keyword
//     // main is an identifier
//     // return is a keyword
//     // 0 is a number
//     // fclose is an identifier

// ############################################################
// Write a C program takes two text files “stop_words.txt”, and
// “story.txt”. It then removes all the stop word occurrences in the
// “story.txt” file by matching with “stop_words.txt” . After removing all
// stop words create a file called “story_without_stopwords.txt”, which
// will contains sentences without any stop word.

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX_STOP_WORDS 1000
// #define MAX_WORD_LENGTH 100
// #define MAX_LINE_LENGTH 1024

// int main() {
//     FILE *stop_file = fopen("stop_words.txt", "r");
//     FILE *story_file = fopen("story.txt", "r");
//     FILE *output_file = fopen("story_without_stopwords.txt", "w");

//     if (!stop_file || !story_file || !output_file) {
//         perror("Error opening file");
//         return EXIT_FAILURE;
//     }

//     // Load stop words from comma-separated values
//     char stop_words[MAX_STOP_WORDS][MAX_WORD_LENGTH];
//     int stop_count = 0;
//     char stop_line[MAX_LINE_LENGTH];

//     if (fgets(stop_line, sizeof(stop_line), stop_file)) {
//         char *token = strtok(stop_line, ",");
//         while (token && stop_count < MAX_STOP_WORDS) {
//             // Trim leading and trailing whitespace
//             while (isspace((unsigned char)*token)) token++;
//             char *end = token + strlen(token) - 1;
//             while (end > token && isspace((unsigned char)*end)) {
//                 *end = '\0';
//                 end--;
//             }
//             // Convert to lowercase
//             for (char *p = token; *p; ++p) *p = tolower((unsigned char)*p);
//             strcpy(stop_words[stop_count++], token);
//             token = strtok(NULL, ",");
//         }
//     }
//     fclose(stop_file);

//     // Process the story file
//     char line[MAX_LINE_LENGTH];
//     while (fgets(line, sizeof(line), story_file)) {
//         int len = strlen(line);
//         int i = 0;
//         while (i < len) {
//             if (!isalpha((unsigned char)line[i])) {
//                 // Write non-letter characters directly
//                 fputc(line[i], output_file);
//                 i++;
//             } else {
//                 // Build the word
//                 char word[MAX_WORD_LENGTH];
//                 int word_len = 0;
//                 int start = i;
//                 while (i < len && isalpha((unsigned char)line[i])) {
//                     word[word_len++] = line[i++];
//                 }
//                 word[word_len] = '\0';

//                 // Convert word to lowercase for comparison
//                 char lower_word[MAX_WORD_LENGTH];
//                 for (int j = 0; j <= word_len; j++) {
//                     lower_word[j] = tolower((unsigned char)word[j]);
//                 }

//                 // Check if the word is a stop word
//                 int is_stop = 0;
//                 for (int k = 0; k < stop_count; k++) {
//                     if (strcmp(lower_word, stop_words[k]) == 0) {
//                         is_stop = 1;
//                         break;
//                     }
//                 }

//                 if (!is_stop) {
//                     // Write the original word to output
//                     fwrite(&line[start], sizeof(char), word_len, output_file);
//                 }
//                 // Skip the word if it's a stop word
//             }
//         }
//     }

//     fclose(story_file);
//     fclose(output_file);
//     return EXIT_SUCCESS;
// }
// // Explanation:
// // 1. Defines maximum limits for stop words, word length, and line length.
// // 2. Opens "stop_words.txt" and reads all stop words into an array.
// // 3. Opens "story.txt" for reading the original story.
// // 4. Opens (or creates) "story_without_stopwords.txt" for writing the processed story.
// // 5. Reads each line from "story.txt" and tokenizes it into words.
// // 6. Converts each word to lowercase to ensure case-insensitive comparison.
// // 7. Checks if the word is present in the stop words array.
// // 8. If the word is not a stop word, writes it to the output file.
// // 9. Continues this process until the entire story is processed.
// // 10. Closes all opened files to ensure data is saved and resources are freed.
// // 11. Notifies the user upon successful removal of stop words.

// ###########################################################################################
// Design a lexical analyzer for given language and the lexical analyzer should ignore redundant spaces, tabs and new lines. It should also ignore comments. Although the syntax specification states that identifiers can be arbitrarily long, you may restrict the length to some reasonable value. Simulate the same in C language. After lexical analysis separate file for each type of tokens will be created.
// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// #define MAX_ID_LEN 31

// void tokenize(const char *filename);

// int main() {
//     tokenize("code.c");
//     return 0;
// }

// void tokenize(const char *filename) {
//     FILE *fp = fopen(filename, "r");
//     if (!fp) {
//         printf("Failed to open file.\n");
//         return;
//     }

//     FILE *f_id = fopen("identifiers.txt", "w");
//     FILE *f_kw = fopen("keywords.txt", "w");
//     FILE *f_op = fopen("operators.txt", "w");
//     FILE *f_num = fopen("numbers.txt", "w");
//     // Add more files as needed

//     char ch;
//     char buffer[100];
//     int idx = 0;

//     const char *keywords[] = {"int", "float", "if", "else", "while", "return", NULL};
//     const char *operators = "+-*/=%><!";

//     while ((ch = fgetc(fp)) != EOF) {
//         // Ignore whitespace
//         if (ch == ' ' || ch == '\t' || ch == '\n') continue;

//         // Ignore comments
//         if (ch == '/') {
//             char next = fgetc(fp);
//             if (next == '/') {
//                 // Single-line comment
//                 while ((ch = fgetc(fp)) != EOF && ch != '\n');
//                 continue;
//             } else if (next == '*') {
//                 // Multi-line comment
//                 while ((ch = fgetc(fp)) != EOF) {
//                     if (ch == '*' && (next = fgetc(fp)) == '/') break;
//                 }
//                 continue;
//             } else {
//                 ungetc(next, fp);
//             }
//         }

//         // Identifiers and keywords
//         if (isalpha(ch) || ch == '_') {
//             idx = 0;
//             buffer[idx++] = ch;
//             while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_')) {
//                 if (idx < MAX_ID_LEN) {
//                     buffer[idx++] = ch;
//                 }
//             }
//             buffer[idx] = '\0';
//             ungetc(ch, fp);

//             // Check if keyword
//             int isKeyword = 0;
//             for (int i = 0; keywords[i] != NULL; i++) {
//                 if (strcmp(buffer, keywords[i]) == 0) {
//                     fprintf(f_kw, "%s\n", buffer);
//                     isKeyword = 1;
//                     break;
//                 }
//             }
//             if (!isKeyword) {
//                 fprintf(f_id, "%s\n", buffer);
//             }
//             continue;
//         }

//         // Numbers
//         if (isdigit(ch)) {
//             idx = 0;
//             buffer[idx++] = ch;
//             while ((ch = fgetc(fp)) != EOF && isdigit(ch)) {
//                 buffer[idx++] = ch;
//             }
//             buffer[idx] = '\0';
//             ungetc(ch, fp);
//             fprintf(f_num, "%s\n", buffer);
//             continue;
//         }

//         // Operators
//         if (strchr(operators, ch)) {
//             idx = 0;
//             buffer[idx++] = ch;
//             ch = fgetc(fp);
//             if (ch == '=' || (buffer[0] == ch)) {
//                 buffer[idx++] = ch;
//             } else {
//                 ungetc(ch, fp);
//             }
//             buffer[idx] = '\0';
//             fprintf(f_op, "%s\n", buffer);
//             continue;
//         }

//         // Handle other tokens like delimiters, literals, etc. as needed
//     }

//     fclose(fp);
//     fclose(f_id);
//     fclose(f_kw);
//     fclose(f_op);
//     fclose(f_num);
//     // Close other files as needed
// }

// // Explanation:
// // 1. Defines the maximum identifier length with MAX_ID_LEN.
// // 2. Implements the `tokenize` function to analyze the given C source file.
// // 3. Opens the source file (`code.c`) for reading.
// // 4. Creates separate files for identifiers, keywords, operators, and numbers.
// // 5. Reads the source file character by character, ignoring redundant spaces, tabs, and new lines.
// // 6. Identifies and categorizes tokens such as identifiers, keywords, and operators.
// // 7. Writes each identified token to its corresponding file.
// // 8. Closes all opened files to ensure data is saved and resources are freed.


// // Sample Input:
// // Contents of code.c:
// // int main() {
// //     int a = 5;
// //     float b = 3.14;
// //     if(a > b) {
// //         return a;
// //     }
// //     return 0;
// // }

// // Sample Output:
// // Contents of identifiers.txt:
// // main
// // a
// // b

// // Contents of keywords.txt:
// // int
// // int
// // float
// // if
// // return
// // return

// // Contents of operators.txt:
// // (
// // )
// // {
// // =
// // ;
// // =
// // ;
// // >
// // )
// // {
// // }
// // return
// // ;
// // return
// // ;

// // Contents of numbers.txt:
// // 5
// // 3.14
// // a
// // 0

// ############################################################
// Write a program to take C program as input and identify all types comment line inside the program.  After identifying all types of comment line it’s needs to be written back to a separate file.
// #include <stdio.h>   
// #include <stdlib.h>
// #include <string.h>

// void extract_comments(const char *filename);

// int main() {
//     extract_comments("code.c");
//     return 0;
// }

// void extract_comments(const char *filename) {
//     FILE *fp = fopen(filename, "r");
//     if (!fp) {
//         printf("Failed to open file.\n");
//         return;
//     }

//     FILE *f_single = fopen("single_comments.txt", "w");
//     FILE *f_multi = fopen("multi_comments.txt", "w");

//     char ch;
//     char next;

//     while ((ch = fgetc(fp)) != EOF) {
//         if (ch == '/') {
//             next = fgetc(fp);
//             if (next == '/') {
//                 // Single-line comment
//                 while ((ch = fgetc(fp)) != EOF && ch != '\n') {
//                     fputc(ch, f_single);
//                 }
//                 fputc('\n', f_single);
//             } else if (next == '*') {
//                 // Multi-line comment
//                 fputc('/', f_multi);
//                 fputc('*', f_multi);
//                 while ((ch = fgetc(fp)) != EOF) {
//                     fputc(ch, f_multi);
//                     if (ch == '*' && (next = fgetc(fp)) == '/') {
//                         fputc(next, f_multi);
//                         break;
//                     }
//                 }
//             } else {
//                 ungetc(next, fp);
//             }
//         }
//     }

//     fclose(fp);
//     fclose(f_single);
//     fclose(f_multi);
// }

// // Explanation:
// // 1. Defines the `extract_comments` function to process a given C source file.
// // 2. Opens the source file (`code.c`) for reading.
// // 3. Creates two separate files: `single_comments.txt` for single-line comments and `multi_comments.txt` for multi-line comments.
// // 4. Reads the source file character by character using `fgetc`.
// // 5. Detects single-line comments starting with `//` and writes them to `single_comments.txt`.
// // 6. Detects multi-line comments starting with `/*` and writes them to `multi_comments.txt`.
// // 7. Continues processing until the end of the source file.
// // 8. Closes all opened files to ensure data is saved and resources are freed.
// // 9. Notifies the user upon successful extraction of comments.

// // Sample Input:
// // Contents of code.c:
// // #include <stdio.h>
// // 
// // // This is a single-line comment
// // /* This is a 
// //    multi-line comment */
// // int main() {
// //     printf("Hello, World!\n"); // Another single-line comment
// //     return 0;
// // }

// // Sample Output:
// // Contents of single_comments.txt:
// // This is a single-line comment
// // Another single-line comment

// // Contents of multi_comments.txt:
// // /* This is a 
// //    multi-line comment */
// #######################################################
// Write a C program to recognize strings under 'a*', 'a*b+', 'abb'
// #include <stdio.h>
// #include <string.h>

// int match_a_star(const char *str) {
//     // Check if the string consists of zero or more 'a's
//     for (int i = 0; str[i]; i++) {
//         if (str[i] != 'a') return 0;
//     }
//     return 1;
// }

// int match_a_star_b_plus(const char *str) {
//     int i = 0;
//     // Zero or more 'a's
//     while (str[i] == 'a') i++;
//     // Must have at least one 'b'
//     if (str[i] != 'b') return 0;
//     while (str[i] == 'b') i++;
//     // Should reach the end
//     return str[i] == '\0';
// }

// int match_abb(const char *str) {
//     return strcmp(str, "abb") == 0;
// }

// int main() {
//     char input[100];
//     printf("Enter a string: ");
//     scanf("%s", input);
    
//     if (match_a_star(input)) {
//         printf("The string matches 'a*'\n");
//     } else {
//         printf("The string does not match 'a*'\n");
//     }

//     if (match_a_star_b_plus(input)) {
//         printf("The string matches 'a*b+'\n");
//     } else {
//         printf("The string does not match 'a*b+'\n");
//     }

//     if (match_abb(input)) {
//         printf("The string matches 'abb'\n");
//     } else {
//         printf("The string does not match 'abb'\n");
//     }

//     return 0;
// }

// // Explanation:
// // 1. Defines three functions to match different string patterns: 'a*', 'a*b+', and 'abb'.
// // 2. `match_a_star` checks if the string contains zero or more 'a's only.
// // 3. `match_a_star_b_plus` checks if the string has zero or more 'a's followed by one or more 'b's and nothing else.
// // 4. `match_abb` specifically checks if the string is exactly "abb".
// // 5. In the `main` function, the program prompts the user to enter a string.
// // 6. It then checks if the entered string matches the 'a*' pattern and prints the result.
// // 7. Similar checks can be added for the other patterns as needed.

// // Sample Input:
// // Enter a string: aaa
// // Enter a string: aabbb
// // Enter a string: abb
// // Enter a string: abba

// // Sample Output:
// // The string matches 'a*'
// // The string does not match 'a*'
// // The string does not match 'a*'
// // The string does not match 'a*'

// #######################################################
// 1. Write a Lex Program to find whether a given letter is a vowel or not.
// %{
// #include <stdio.h>
// %}

// %%
// [aeiouAEIOU]   { printf("Vowel\n"); }
// [a-zA-Z]       { printf("Not a vowel\n"); }
// .              { /* Ignore any non-alphabet character */ }
// %%

// int main() {
//     printf("Enter a letter: ");
//     yylex();
//     return 0;
// }

// int yywrap() {
//     return 1;
// }

// // // // command to run
// //   flex filename.l
// //  gcc lex.yy.c
// //  ./a.out
// #######################################################
// Write a Lex Program to find Capital letters.
// %{
// #include <stdio.h>
// %}

// %%
// [A-Z]        { printf("Capital letter: %c\n", yytext[0]); }
// .            { /* Ignore other characters */ }
// %%

// int main() {
//     printf("Enter text: ");
//     yylex();
//     return 0;
// }

// int yywrap() {
//     return 1;
// }
// // Explanation:
// // 1. Includes necessary headers for standard I/O and string operations.
// // 2. Defines the Lex rules between the %% delimiters.
// //    - [A-Z]: Matches any uppercase letter from A to Z and prints it as a capital letter.
// //    - .   : Matches any other character and ignores it.
// // 3. The `main` function prompts the user to enter text and calls `yylex()` to start lexical analysis.
// // 4. The `yywrap` function returns 1 to indicate no further input, ending the lexical analysis.
// // 5. When the user inputs text, the program scans it and identifies all capital letters, printing each one found.

// //  command to run
// //   flex filename.l
// //  gcc lex.yy.c
// //  ./a.out

// // Sample Input:
// // Enter text: Hello World! This is a Test.

// // Sample Output:
// // Capital letter: H
// // Capital letter: W
// // Capital letter: T

// #######################################################
// Write a Lex program to count the number of lines,  tabs, and spaces used in the input.
// %{
// #include <stdio.h>

// int line_count = 0;
// int tab_count = 0;
// int space_count = 0;
// %}

// %%
// \n              { line_count++; }       // Count lines
// \t              { tab_count++; }        // Count tabs
// [ ]             { space_count++; }      // Count spaces
// .               { /* Ignore other characters */ }
// %%

// int main() {
//     printf("Enter text (Ctrl+D to end):\n");
//     yylex();
//     printf("Number of lines: %d\n", line_count);
//     printf("Number of tabs: %d\n", tab_count);
//     printf("Number of spaces: %d\n", space_count);
//     return 0;
// }

// int yywrap() {
//     return 1;
// }
// // Explanation:
// // 1. Includes the standard I/O library.
// // 2. Initializes counters for lines, tabs, and spaces.
// // 3. Defines Lex rules:
// //    - \n: Increment line_count on encountering a newline character.
// //    - \t: Increment tab_count on encountering a tab character.
// //    - [ ]: Increment space_count on encountering a space character.
// //    - . : Ignore all other characters.
// // 4. In the `main` function:
// //    - Prompts the user to enter text.
// //    - Calls `yylex()` to start lexical analysis.
// //    - After input ends (Ctrl+D), it prints the counts of lines, tabs, and spaces.
// // 5. `yywrap` function returns 1 to indicate no further input, ending the lexical analysis.

// // command to run
// //   flex filename.l
// //  gcc lex.yy.c
// //  ./a.out

// // Sample Input:
// // Enter text (Ctrl+D to end):
// // Hello World
// // This is a test.
// // 		(Tab before this line)

// // Sample Output:
// // Number of lines: 3
// // Number of tabs: 1
// // Number of spaces: 5


// #######################################################
// // Write a Lex program to take input from a file and remove multiple spaces, newline and tab and write output in a separate file.
// %{
// #include <stdio.h>
// %}

// %%

// [ \t]+          { /* Ignore multiple spaces and tabs */ }
// [\r\n]+         { putchar('\n'); }  /* Replace multiple newlines and carriage returns with a single newline */
// .               { putchar(yytext[0]); }

// %%

// int yywrap() {
//     return 1;
// }

// int main(int argc, char **argv) {
//     if (argc > 1) {
//         FILE *input = fopen(argv[1], "r");
//         if (!input) {
//             perror("fopen");
//             return 1;
//         }
//         yyin = input;
//     }

//     if (argc > 2) {
//         FILE *output = freopen(argv[2], "w", stdout);
//         if (!output) {
//             perror("freopen");
//             return 1;
//         }
//     }

//     yylex();

//     return 0;
// }

// // Explanation:
// // 1. Includes the standard I/O library.
// // 2. Defines Lex rules to ignore multiple spaces and tabs, replace multiple newlines with a single newline, and print all other characters.
// // 3. The `yywrap` function returns 1 to indicate no further input, ending the lexical analysis.
// // 4. In the `main` function:
// //    - Checks if command-line arguments are provided for input and output files.
// //    - Opens the input file for reading and sets it as the input stream.
// //    - Opens the output file for writing and redirects standard output to it.
// //    - Calls `yylex()` to start lexical analysis.
// // 5. The Lex program reads input from the file, removes multiple spaces, newlines, and tabs, and writes the output to a separate file.

// // command to run
// //   flex filename.l
// //  gcc lex.yy.c
// //  ./a.out input.txt output.txt

// // Sample Input:
// // Contents of input.txt:
// // Hello    World
// // This is a test.
// // 		(Tab before this line)

// // Sample Output:
// // Contents of output.txt:
// // Hello World
// // This is a test.
// // (Tab before this line)

// #######################################################
// Write a C program to simulate lexical analyzer for validating operators.
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     char s[5]; // Array to store the operator input
//     system("clear"); // Clear the screen

//     printf("\n Enter any operator:");
//     fgets(s, sizeof(s), stdin); // Read the operator input from the user

//     switch(s[0]) // Switch on the first character of the input
//     {
//         case '>':
//             if(s[1] == '=') // Check if the second character is '='
//                 printf("\n Greater than or equal");
//             else
//                 printf("\n Greater than");
//             break;
//         case '<':
//             if(s[1] == '=')
//                 printf("\n Less than or equal");
//             else
//                 printf("\n Less than");
//             break;
//         case '*':
//             printf("\n Multiplication");
//             break;
//         case '/':
//             printf("\n Division");
//             break;
//         case '%':
//             printf("\n Modulus");
//             break;
//         case '+':
//             printf("\n Addition");
//             break;
//         case '-':
//             printf("\n Subtraction");
//             break;
//         case '&':
//             printf("\n Bitwise AND");
//             break;
//         case '|':
//             printf("\n Bitwise OR");
//             break;
//         case '^':
//             printf("\n Bitwise XOR");
//             break;
//         case '=':
//             if(s[1] == '=')
//                 printf("\n Equal to");
//             else
//                 printf("\n Assignment");
//             break;
//         case '!':
//             if(s[1] == '=')
//                 printf("\n Not equal to");
//             else
//                 printf("\n Logical NOT");
//             break;
//         default:
//             printf("\n Not an operator");
//     }

//     return 0;
// }
// // Explanation:
// // 1. Declares an array `s` to store the operator input.
// // 2. Clears the screen using `system("clear")`.
// // 3. Prompts the user to enter an operator.
// // 4. Reads the operator input using `fgets`.
// // 5. Switches on the first character of the input to identify the operator.
// // 6. Checks the second character if needed to differentiate between operators like `>=`, `<=`, `==`, `!=`.
// // 7. Prints the corresponding operator based on the input.
// // 8. Handles the default case when the input is not a recognized operator.

// // Sample Input:
// // Enter any operator: <=

// // Sample Output:
// // Less than or equal

// #######################################################
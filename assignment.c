11)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int quantity;
} ProductPacket;
ProductPacket* resizeInventory(ProductPacket* inventory, int oldSize, int newSize);
int main() {
    int initialSize = 10;
    int newSize;
    ProductPacket* inventory = malloc(initialSize * sizeof(ProductPacket));

    if (inventory == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < initialSize; i++) {
        inventory[i].id = i + 1;
        snprintf(inventory[i].name, sizeof(inventory[i].name), "Product %d", i + 1);
        inventory[i].quantity = 10 + i;
    }
    printf("Initial Inventory:\n");
    for (int i = 0; i < initialSize; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
    printf("\nEnter new inventory size: ");
    scanf("%d", &newSize);
    inventory = resizeInventory(inventory, initialSize, newSize);
    if (inventory == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        return 1;
    }
    if (newSize > initialSize){
        for (int i = initialSize; i < newSize; i++) {
            inventory[i].id = i + 1;
            snprintf(inventory[i].name, sizeof(inventory[i].name), "New Product %d", i + 1);
            inventory[i].quantity = 0;
        }
    }
    printf("\nUpdated Inventory:\n");
    for (int i = 0; i < newSize; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
    free(inventory);
    return 0;
}
ProductPacket* resizeInventory(ProductPacket* inventory, int oldSize, int newSize) {
    ProductPacket* newInventory = realloc(inventory, newSize * sizeof(ProductPacket));
    if (newInventory == NULL) {
        free(inventory);
        return NULL;
    }
    return newInventory;
}



12)
#include <stdio.h>
int main() {
    float weights[5];
    float totalWeight = 0.0;
    printf("Enter the weights of the 5 treasures:\n");
    for (int i = 0; i < 5; i++) {
        printf("Weight of treasure %d: ", i + 1);
        scanf("%f", &weights[i]);
    }
    for (int i = 0; i < 5; i++) {
        totalWeight += weights[i];
    }
    printf("Total weight of treasures collected: %.2f\n", totalWeight);
    return 0;
}


13)
#include <stdio.h>
#include <string.h>
#define SHAPE_SQUARE 1
#define SHAPE_RECTANGLE 2
typedef union {
    float area;           
    struct {
        float length;     
        float breadth;
    } rectangle;          
} ShapeData;
typedef struct {
    int shapeType;        
    ShapeData data;       
} Shape;
void printShapeDetails(const Shape *shape);
int main() {
    Shape square, rectangle;
    square.shapeType = SHAPE_SQUARE;
    square.data.area = 25.0;  
    rectangle.shapeType = SHAPE_RECTANGLE;
    rectangle.data.rectangle.length = 10.0;
    rectangle.data.rectangle.breadth = 5.0;
    printf("Details of shapes:\n");
    printShapeDetails(&square);
    printShapeDetails(&rectangle);
    return 0;
}
void printShapeDetails(const Shape *shape) {
    if (shape->shapeType == SHAPE_SQUARE) {
        printf("Square:\n");
        printf("Area: %.2f\n", shape->data.area);
    } else if (shape->shapeType == SHAPE_RECTANGLE) {
        printf("Rectangle:\n");
        printf("Length: %.2f\n", shape->data.rectangle.length);
        printf("Breadth: %.2f\n", shape->data.rectangle.breadth);
    } else {
        printf("Unknown shape type\n");
    }
    printf("\n");
}


14)
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100  
#define NAME_LENGTH 50    
typedef struct {
    char name[NAME_LENGTH];
} Student;
void addStudent(Student students[], int *count, const char *name);
void printStudentList(const Student students[], int count);
int main() {
    Student students[MAX_STUDENTS];
    int count = 0;  
    char name[NAME_LENGTH];
    int numSubmissions;
    printf("Enter the number of students submitting their assignments: ");
    scanf("%d", &numSubmissions);
    getchar(); 
    if (numSubmissions > MAX_STUDENTS) {
        printf("Error: The number of students exceeds the maximum limit of %d.\n", MAX_STUDENTS);
        return 1;
    }
    for (int i = 0; i < numSubmissions; i++) {
        printf("Enter the name of student %d: ", i + 1);
        fgets(name, NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = '\0';

        addStudent(students, &count, name);
    }
    printf("\nList of students who have submitted their assignments:\n");
    printStudentList(students, count);

    return 0;
}
void addStudent(Student students[], int *count, const char *name) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Cannot add more students. The list is full.\n");
        return;
    }
    strncpy(students[*count].name, name, NAME_LENGTH);
    students[*count].name[NAME_LENGTH - 1] = '\0'; 
    (*count)++;
}
void printStudentList(const Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, students[i].name);
    }
}


15)
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id; 
} Book;
void printBookList(const Book books[], int count);
int binarySearch(const Book books[], int count, int id);
int main() {
    int numBooks;
    printf("Enter the number of books in the library: ");
    scanf("%d", &numBooks);
    Book *books = (Book *)malloc(numBooks * sizeof(Book));
    if (books == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter the book IDs in ascending order:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book ID %d: ", i + 1);
        scanf("%d", &books[i].id);
    }
    printf("\nLibrary Book IDs:\n");
    printBookList(books, numBooks);
    int searchID;
    printf("\nEnter the Book ID to search: ");
    scanf("%d", &searchID);
    int result = binarySearch(books, numBooks, searchID);
    if (result != -1) {
        printf("Book ID %d is available in the library.\n", searchID);
    } else {
        printf("Book ID %d is not available in the library.\n", searchID);
    }
    free(books);
    return 0;
}
void printBookList(const Book books[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", books[i].id);
    }
    printf("\n");
}
int binarySearch(const Book books[], int count, int id) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (books[mid].id == id) {
            return mid;  
        }
        if (books[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  
}

16)
#include <stdio.h>

#define ROWS 2
#define COLS 2
void printMatrix(int matrix[ROWS][COLS], int rows, int cols);
void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS], int rows, int cols);
int main() {
    int matrixA[ROWS][COLS] = {{3,4,2,4}}; 
    int matrixB[ROWS][COLS] = {{1,2,3,4}}; 
    int result[ROWS][COLS]; 
    addMatrices(matrixA, matrixB, result, ROWS, COLS);
    printf("Resultant matrix after addition:\n");
    printMatrix(result, ROWS, COLS);

    return 0;
}
void printMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}





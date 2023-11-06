#ifndef DOG_H
#define DOG_H

/**
 * struct dog - class or struct for Dog
 *
 * @name: The Dog's name
 *
 * @age: The dog's age
 *
 * @owner: Owner of the dog
 *
 * Description: This is the struct for the dog
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

typedef struct dog dog_t;

dog_t *new_dog(char *name, float age, char *owner);

void free_dog(dog_t *d);
#endif

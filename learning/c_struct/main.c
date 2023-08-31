#include <stdlib.h>
#include <stdio.h>

typedef struct s_player
{
    void    (*say)(char *);
    int     age;
    int     (*get_age)(void *);
}   t_player;

int get_age(void *p)
{
    return ((t_player *) p)->age;
}

void    say(char *sentence)
{
    printf("%s\n", sentence);
}

t_player    *new_player(int age)
{
    t_player *p;

    p = (t_player *) calloc(1, sizeof(t_player));
    p->get_age = get_age;
    p->say = say;
    p->age = age;
    return p;
}

void    delete_player(t_player *p)
{
    if (p)
        free(p);
}

int main(void)
{
    t_player    *p;

    p = new_player(35);
    printf("age: %d\n", p->get_age(p));
    p->say("IHAAAAAAAAA");
    delete_player(p);
    return 0;
}
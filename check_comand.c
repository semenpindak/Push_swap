#include "push_swap.h"

void check_comand_two(t_number **list_a, t_number **list_b)
{


pb_three(&list_a, &list_b);
show_me_three(&list_a, &list_b);

pa_three(&list_a, &list_b);
show_me_three(&list_a, &list_b);

pb_three(&list_a, &list_b);
show_me_three(&list_a, &list_b);

pa_three(&list_a, &list_b);
show_me_three(&list_a, &list_b);
// ra_three(&list_a);
// rb_three(&list_b);
// rr_three(&list_a, &list_b);
// rra_three(&list_a);
// rrb_three(&list_b);
// rrr_three(&list_a, &list_b);
}

void check_comand(t_number *list_a, t_number *list_b)
{
sa(list_a);
show_me_two(&list_a, &list_b);

pb(&list_a, &list_b);
show_me_two(&list_a, &list_b);

pb(&list_a, &list_b);
show_me_two(&list_a, &list_b);

// sb(list_b);
// ss(list_a, list_b);

// pa(&list_a, &list_b);
// show_me_two(&list_a, &list_b);

// pa(&list_a, &list_b);
// show_me_two(&list_a, &list_b);

pb(&list_a, &list_b);
show_me_two(&list_a, &list_b);
// ra(&list_a);
// rb(&list_b);
// rr(&list_a, &list_b);
// rra(&list_a);
// rrb(&list_b);
// rrr(&list_a, &list_b);

check_comand_two(&list_a, &list_b);
printf("1\n");

pb(&list_a, &list_b);
show_me_two(&list_a, &list_b);

pa(&list_a, &list_b);
show_me_two(&list_a, &list_b);

check_comand_two(&list_a, &list_b);
}

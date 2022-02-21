void	print_game(t_game *g)
{
	t_stack	*a;;
	t_stack	*b;

	a = g->a;
	b = g->b;
	while (a || b)
	{
		if (a && b)
		{
			printf("%s        %s\n", a->bin, b->bin);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("%s        \n", a->bin);
			a = a->next;
		}
		else if (!a && b)
		{
			printf("        %s\n", b->bin);
			b = b->next;
		}
	}
	printf("--       --\n");
	printf("a.........b\n\n");
}
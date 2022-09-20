void freestuff(node* head)
{
    node* cursor;
    node* last_visited = NULL;
    cursor = head;

    while (cursor)
    {
        if(last_visited)
        {
            free(cursor);
        }

        free(cursor->color);
        free(cursor->details[0]);
        free(cursor->details[1]);
        free(cursor->details);
        last_visited = cursor;
        cursor = cursor->next;
    }

    free(last_visited);
}
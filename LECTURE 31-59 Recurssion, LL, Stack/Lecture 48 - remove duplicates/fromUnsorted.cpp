//app1

Node *removeDuplicates(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *curr = head;

    while (curr != NULL) {
        Node *prev = curr;
        Node *temp = curr->next;

        while (temp != NULL) {
            if (curr->data == temp->data) {
                // Remove the duplicate node
                prev->next = temp->next;
                Node *nodeToDel = temp;
                temp = temp->next; // Move temp to the next node before deleting
                delete nodeToDel;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

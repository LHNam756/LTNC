SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newTail = new SinglyLinkedListNode(data);
    if (head == nullptr) {
        head = newTail;
    } else {
        SinglyLinkedListNode* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newTail;
    }
    return head;
}


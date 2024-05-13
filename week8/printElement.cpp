void printLinkedList(SinglyLinkedListNode* head) {
    for(SinglyLinkedListNode    *p = head; p != NULL; p = p->next){
        cout << p->data << endl;
    }

}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(!head1) {
        return head2;
    }
    if(!head2) {
        return head1;
    }
    
    SinglyLinkedListNode* head = nullptr;
    
    if(head1->data < head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }
    
    SinglyLinkedListNode* curr = head;
    
    while(head1 && head2) {
        if(head1->data < head2->data){
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    
    if(head1) {
        curr->next = head1;
    }
    if(head2) {
        curr->next = head2;
    }
    return head;

}
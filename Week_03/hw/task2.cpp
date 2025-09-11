/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(!llist) {
        return llist;
    }
    
    SinglyLinkedListNode* curr = llist;
    SinglyLinkedListNode* prev = nullptr;
    prev = curr;
    curr = curr->next;
    while (curr) {
        if(prev->data == curr->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
        
    }
    
    return llist;

}
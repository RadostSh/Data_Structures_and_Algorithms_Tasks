/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if(!llist) {
        return llist;
    }
    
    SinglyLinkedListNode* curr = llist;
    SinglyLinkedListNode* prev = nullptr;
    
    for(int i = 0; i < position; i++) {
        if(curr){
        prev = curr;
        curr = curr->next;
        }
     else {
        return nullptr;
    }
    }
    
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    prev->next = newNode;
    newNode->next = curr;
    
    return llist;
}
int c=0;
Node* temp = head;
while(c<2){
    temp = temp -> next;
    c++;
}

tail -> next = temp;
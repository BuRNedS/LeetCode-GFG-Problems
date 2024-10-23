int sumOfLastN_Nodes(struct Node* head, int n) {
            struct Node* temp = head;
    int cnt = 0;

    while (temp) {
        cnt++;
        temp = temp->next;
    }

    int sum = 0;
    
    temp = head;

    for (int i = 0; i < cnt - n; i++) {
        temp = temp->next;
    }

    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;

        
    }

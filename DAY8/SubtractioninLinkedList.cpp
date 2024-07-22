//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++


Node* subLinkedList(Node* head1, Node* head2) {
        string s1="", s2="";
        while(head1!=NULL){
            s1+=to_string(head1->data);
            head1=head1->next;
        }
        
         while(head2!=NULL){
            s2+=to_string(head2->data);
            head2=head2->next;
        }
        
        int flag1=0, flag2=0;
        string str1="", str2="";
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!='0') flag1=1;
            if(flag1) str1+=s1[i];
        }
         for(int i=0; i<s2.size(); i++){
            if(s2[i]!='0') flag2=1;
            if(flag2) str2+=s2[i];
        }
        
        int len1=str1.size();
        int len2=str2.size();
        
        string str="";
        if(len1==len2 && len1==0) str+='0';
        else if(len1==len2){
            int t=0;
            for(int i=0; i<len1; i++){
                if(str1[i]-'0'<str2[i]-'0'){
                    t=1;
                    break;
                }
                 if(str1[i]-'0'>str2[i]-'0'){
                    t=2;
                    break;
                }
            }
            if(t==0){ 
                str+='0';
            }else if(t==1){
                int carry=0;
                for(int i=len1-1; i>=0; i--){
                    if((str2[i]-'0')-carry-(str1[i]-'0')>=0){
                        str+=to_string((str2[i]-'0')-carry-(str1[i]-'0'));
                        carry=0;
                    }else{
                        str+=to_string(10+(str2[i]-'0')-carry-(str1[i]-'0'));
                        carry=1;
                    }
                }
            }  else{
                int carry=0;
                for(int i=len1-1; i>=0; i--){
                    if((str1[i]-'0')-carry-(str2[i]-'0')>=0){
                        str+=to_string((str1[i]-'0')-carry-(str2[i]-'0'));
                        carry=0;
                    }else{
                        str+=to_string(10+(str1[i]-'0')-carry-(str2[i]-'0'));
                        carry=1;
                    }
                }
            }
        }else if(len1<len2){
            str1 = string(len2-len1, '0') + str1;
                int carry=0;
                for(int i=len2-1; i>=0; i--){
                    int digit2=str2[i]-'0';
                    int digit1=str1[i]-'0';
                    if(digit2-carry-digit1>=0){
                        str+=to_string(digit2-carry-digit1);
                        carry=0;
                    }else{
                        str+=to_string(10+digit2-carry-digit1);
                        carry=1;
                    }
                }
            }else{
                str2 = string(len1-len2, '0') + str2;
                 int carry=0;
                for(int i=len1-1; i>=0; i--){
                    int digit1=str1[i]-'0';
                    int digit2=str2[i]-'0';
                    if(digit1-carry-digit2>=0){
                        str+=to_string(digit1-carry-digit2);
                        carry=0;
                    }else{
                        str+=to_string(10+digit1-carry-digit2);
                        carry=1;
                    }
                }
            } 
            reverse(str.begin(), str.end());
            string ans="";
            int idx=-1;
            for(int i=0; i<str.size(); i++){
                if(str[i]!='0'){
                    idx=i;
                    break;
                }
            }
            
            // ans.erase(0, min(ans.find_first_not_of('0'), ans.size() - 1)); // to erase leading zeros.
            for(int i=idx; i<str.size(); i++){
                ans+=str[i];
            }
           if(ans.length()==0) ans+='0'; 
         Node *newHead = new Node(ans[0]-'0');
         Node *temp = newHead;

        for (int i = 1; i < ans.length(); i++)
        {
            temp->next = new Node(ans[i]-'0');
            temp = temp->next;
        }
        return newHead;
        return NULL;
        
    }


//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends

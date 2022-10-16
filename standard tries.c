#include <stdio.h>
#include <stdlib.h>
#define CHAR_SIZE 26
struct Trie
{
int isLeaf;
struct Trie* character[CHAR_SIZE];
};
struct Trie* getNewTrieNode()
{
struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
node->isLeaf = 0;
for (int i = 0; i < CHAR_SIZE; i++) {
node->character[i] = NULL;
}
return node;
}
void insert(struct Trie *head, char* str)
{
struct Trie* curr = head;
while (*str)
{
if (curr->character[*str - 'a'] == NULL) {
curr->character[*str - 'a'] = getNewTrieNode();
}
curr = curr->character[*str - 'a'];
Academic Year 2022-23 SAP ID:6003210028
str++;
}
curr->isLeaf = 1;
}
int search(struct Trie* head, char* str)
{
if (head == NULL) {
return 0;
}
struct Trie* curr = head;
while (*str)
{
curr = curr->character[*str - 'a'];
if (curr == NULL) {
return 0;
}
str++;
}
return curr->isLeaf;
}
int hasChildren(struct Trie* curr)
{
for (int i = 0; i < CHAR_SIZE; i++)
{
if (curr->character[i]) {
return 1;
}
Academic Year 2022-23 SAP ID:6003210028
}
return 0;
}
int deletion(struct Trie **curr, char* str)
{
if (*curr == NULL) {
return 0;
}
if (*str)
{
if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
deletion(&((*curr)->character[*str - 'a']), str + 1) &&
(*curr)->isLeaf == 0)
{
if (!hasChildren(*curr))
{
free(*curr);
(*curr) = NULL;
return 1;
}
else {
return 0;
}
}
}
if (*str == '\0' && (*curr)->isLeaf)
{
Academic Year 2022-23 SAP ID:6003210028
if (!hasChildren(*curr))
{
free(*curr);
(*curr) = NULL;
return 1;
}
else {
(*curr)->isLeaf = 0;
return 0;
}
}
return 0;
}
int main()
{
struct Trie* head = getNewTrieNode();
int n;
char s[20],s1[20],s2[20];
printf("How many Elements You want to enter\n");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
printf("Enter element\n");
scanf("%s",s);
insert(head, s);
}
printf("Which element you want to search\n");
Academic Year 2022-23 SAP ID:6003210028
scanf("%s",s1);
if(search(head, s1)==1)
{
printf("Found\n");
}
else
{
printf("Not found");
}
printf("Which element you want to delete\n");
scanf("%s",s2);
deletion(&head, s2);
printf("Element Deleted\n");
return 0;
}

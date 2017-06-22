typedef struct Node{
  struct Node *left;
  struct Node *right;
  int value;
}Node;

Node *root = NULL;
void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Begin");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void insert_node(Node **root,int elemento)
{
  if(*root == NULL) {
      Node *aux = (Node *)malloc(sizeof(Node));
      aux->value = elemento;
      aux->right = aux->left = NULL;
      *root = aux;
      Serial.println("Inserted");
      return;
  }

  if(elemento < (*root)->value) {
      insert_node(&(*root)->left,elemento);
      return;
  }
  if(elemento > (*root)->value) {
      insert_node(&(*root)->right,elemento);
      return;
  }
  Serial.println("Already Exists");
}

Node *two_leafs(Node *root){
      if(root==NULL)
          return NULL;
      else if(root->left == NULL)
              return root;
      else
          return two_leafs(root->left);
}

void remove_node(Node**root,int elemento){
  if(elemento < (*root)->value){
      remove_node(&(*root)->left,elemento);
  }
  else if(elemento > (*root)->value){
      remove_node(&(*root)->right,elemento);
  }
  else if((*root)->left!=NULL && (*root)->right!=NULL){
      Node *aux= NULL;
      aux = two_leafs((*root)->right);
      (*root)->value = aux->value;
      remove_node(&(*root)->right,(*root)->value);
  }
  else {
      Node *aux = (*root);
      if((*root)->left==NULL) {
          (*root) = (*root)->right;
      }
      else {
          *root = (*root)->left;
      }
      free(aux);
      Serial.println("Removed");
  }
}

void print_simetrical_order(Node *root){
  if(root == NULL)
      return;
  print_simetrical_order(root->left);
  Serial.println(root->value);
  print_simetrical_order(root->right);
}

void print_pos_order(Node *root){
  if(root == NULL)
      return;
  print_pos_order(root->left);
  print_pos_order(root->right);
  Serial.println(root->value);
}

void print_pre_order(Node *root){
  if(root == NULL)
      return;
  Serial.println(root->value);
  print_pre_order(root->left);
  print_pre_order(root->right);
}











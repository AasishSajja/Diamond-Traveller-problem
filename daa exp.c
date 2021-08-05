#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
int weight;
struct node * next;
};
struct queue_node
{
int start_value;
int weight;
int end_value;
};
struct complete_node
{
int value;
struct node *next;
};
struct returner
{
int value;
int *dist;
int *prev;
};
struct diamond_returner
{
int bag_size;
int max_elem;
int *wt;
int *val;
};
struct returner2
{
struct returner *returned;
};
int no_of_edges; //this has to be modified later
int current_pos = 0; //this has to be modified later
struct returner * prims(struct complete_node arr[],int size,int start);
int display(struct complete_node arr[],int size);
void insert(struct queue_node arr[],struct queue_node val);
struct queue_node delete(struct queue_node arr[]);
struct complete_node * graph_designer(int size);
struct diamond_returner * diamonds_init(int size);
void setter(struct diamond_returner *one,int a);
void knapSack(struct complete_node arr[],int size,int src,int dest,int c1,int
c2);
void path_finder(int *arr,int root1);
void explore(struct complete_node arr[],int j,struct queue_node queue[],int
dist[],int prev[]);
struct node * create_node()
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
printf("\n enter the value of the node : ");
scanf("%d",&temp->value);
printf("\n enter the weight of node : ");
scanf("%d",&(temp->weight));
temp->next = NULL;
return temp;
}
int display(struct complete_node arr[],int size)
{
int i;
int count = 0;
for(i = 0; i < size; i++)
{
struct node *temp = arr[i].next;
//printf("%d : is the value of the node \n",arr[i].value);
while(temp != NULL)
{
//printf("%d \t %d \n",temp->value,temp->weight);
count++;
temp = temp->next;
}
}
return count;
}
void insert(struct queue_node arr[],struct queue_node val)
{
int pos = current_pos +1;
if(pos == 1)
{
arr[pos] = val;
}
else
{
arr[pos] = val;
int parent = pos/2;
//int pos = pos;
while((parent != 0) && arr[parent].weight > arr[pos].weight)
{
struct queue_node temp = arr[parent];
arr[parent] = arr[pos];
arr[pos] = temp;
pos = parent;
parent = parent/2;
}
}
current_pos++;
}
struct queue_node delete(struct queue_node arr[])
{
printf("%d %d %dis the value deleted /n",arr[1].start_value,arr[1].weight,arr[1].end_value);
struct queue_node deleted = arr[1];
arr[1] = arr[current_pos];
int i = 1;
int lc = 2*i;
int rc = 2*i+1;
while((2*i < current_pos) && (arr[i].weight > arr[rc].weight ||
arr[i].weight > arr[lc].weight))
{
if(arr[rc].weight > arr[lc].weight )
{
struct queue_node temp = arr[lc];
arr[lc] = arr[i];
arr[i] = temp;
i = lc;
lc = 2*i;
rc = 2*i+1;
}
else
{
struct queue_node temp = arr[rc];
arr[rc] = arr[i];
arr[i] = temp;
i = rc;
lc = 2*i;
rc = 2*i+1;
if(rc < current_pos)
{
if(arr[i].weight > arr[lc].weight)
{
struct queue_node temp = arr[lc];
arr[lc] = arr[i];
arr[i] = temp;
return deleted;
}
}
}
}
current_pos--;
return deleted;
}
void explore(struct complete_node arr[],int j,struct queue_node queue[],int
dist[],int prev[])
{
struct node *temp = arr[j].next;
struct queue_node temp1;
int len;
while(temp!= NULL)
{
temp1.start_value = arr[j].value;
temp1.end_value = temp->value;
temp1.weight = temp->weight + dist[j];
//prev[temp->value] = arr[j].value;
len = dist[j] + temp->weight;
if(len < dist[temp->value])
{
dist[temp->value] = len;
prev[temp->value] = arr[j].value;
}
insert(queue,temp1);
temp = temp->next;
}
}
struct returner * prims(struct complete_node arr[],int size,int start)
{
int mst_vertices[size]=();
int i;
int no_of_edges = display(arr,size);
int *mst_vertices = (int*)malloc(sizeof(int)*size);
struct queue_node queue[no_of_edges];
int *dist = (int *)malloc(sizeof(int)*size);
struct returner * return_dist_prev = (struct returner*)malloc(sizeof(struct returner));
for(i = 0; i< size; i++)
{
dist[i] = 999;
}
int *prev = (int *)malloc(sizeof(int) * size);
printf("enter the starting node of the tree : ");
scanf("%d",&start);
mst_vertices[start] = 1;
dist[start] = 0;
prev[start] = -1;
explore(arr,start,queue,dist,prev);
int resize = size;
size--;
printf("the edges in the minimum spanning tree are : \n");
while(size--)
{
int add = 0;
while(add != 1)
{
struct queue_node deleted = delete(queue);
if(mst_vertices[deleted.start_value] != 1)
{
explore(arr,deleted.start_value,queue,dist,prev);
mst_vertices[deleted.start_value]=1;
add = 1;
printf("%d %d %d is added into the mst\n",deleted.start_value,deleted.weight,deleted.end_value);
}
else if(mst_vertices[deleted.end_value] !=1)
{
explore(arr,deleted.end_value,queue,dist,prev);
mst_vertices[deleted.end_value] = 1;
add = 1;
printf("%d %d %d is added into the mst\n",deleted.start_value,deleted.weight,deleted.end_value);
}
}
}
return_dist_prev->value= start;
return_dist_prev->dist = dist;
return_dist_prev->prev = prev;
return return_dist_prev;
}
struct complete_node * graph_designer(int size)
{
int i;
struct complete_node *graph = (struct complete_node *)malloc(sizeof(struct
complete_node)*size);
for(i =0; i < size; i++)
{
graph[i].next = (struct node *)malloc(sizeof(struct node));
printf("enter number of the nodes \n ",i);
scanf("%d",&graph[i].value);
graph[i].next = NULL;
int adjacent_nodes;
struct node *last;
printf("enter the no of adjacent nodes : ");
scanf("%d",&adjacent_nodes);
printf("enter the details of the %d node",i);
while(adjacent_nodes--)
{
struct node *temp = create_node();
if(graph[i].next == NULL)
{
graph[i].next = temp;
last = temp;
}
else
{
last->next = temp;
last = temp;
}
}
}
return graph;
}
struct diamond_returner * diamonds_init(int size)
{
int i;
struct diamond_returner *one = (struct diamond_returner*)malloc(sizeof(struct diamond_returner));
printf("enter the maximum capacity of the knap_sacck : ");
scanf("%d",&one->bag_size);
printf("enter the maximum no of elements in bag : ");
scanf("%d",&one->max_elem);
int *wt = (int *)malloc(sizeof(int)*size);
int *val = (int *)malloc(sizeof(int)*size);
for(i = 0; i < size; i++)
{
printf("\n enter the value of the diamond : ");
scanf("%d",&val[i]);
printf("\n enter the weight of the diamond: ");
//printf("%d",&temp->diamond_weight);
scanf("%d",&wt[i]);
}
one->wt = wt;
one->val = val;
return one;
}
int max(int a , int b)
{
return (a>b)?a:b;
}
int min(int a , int b)
{
return (a<b)?a:b;
}
void setter(struct diamond_returner *one,int a)
{
one->wt[a] = 0;
one->val[a] = 0;
}
void knapSack(struct complete_node arr[],int size,int src,int dest,int c1,int
c2)
{
struct diamond_returner *one = diamonds_init(size);
setter(one,src);
setter(one,dest);
setter(one,c1);
setter(one,c2);
int p = one->max_elem;
int W = one->bag_size;
int n = size;
int k,w,i;
int no_of_diamonds = 0;
int K[p+1][W+1][n+1];
for(k = 0; k <= p; k++)
{
for(w = 0; w <=W; w++)
{
for(i = 0; i <= n; i++)
{
if(k == 0 || w == 0 || i== 0)
{
K[k][w][i] = 0;
}
else if(one->wt[i-1] <= w)
{
K[k][w][i] = max(K[k-1][w][i-1],K[k-1][w-one->wt[i-1]][i-1] + one->val[i-1]);
}
else
{
K[k][w][i] = K[k-1][w][i-1];
}
}
}
}
i = n;
w = W;
k = p;
int z = 1;
int pos[3];
while(k > 0)
{
if(K[p][w][i] != K[p-1][w][i-1])
{
printf("\n%d with %d weight and %d value element is in knapsack\n",i,one->wt[i-1],one->val[i-1]);
pos[z-1] = i-1;
no_of_diamonds++;
//locations[z] = *(prims(arr,size,i-1));
i = i-1;
w = w - one->wt[i-1];
k--;
//z++;
}
else
{
i = i-1;
}
}
struct returner *locations = (struct returner *)malloc(sizeof(struct returner)*(no_of_diamonds+2));
struct returner2 *returns = (struct returner2 *)malloc(sizeof(struct
returner2)* (no_of_diamonds+2));
for(i = 0; i < no_of_diamonds+2; i++)
{
returns[i].returned = (struct returner *)malloc(sizeof(struct returner));
}
returns[0].returned = (prims(arr,size,src));
for(z = 0; z < no_of_daimonds; z++)
{
returns[z].returned = (prims(arr,size,pos[z]));
}
if(no_of_diamonds == 3)
{
if(returns[0].returned->dist[pos[0]] > returns[0].returned->dist[pos[1]])
{
int temp = pos[0];
pos[0] = pos[1];
pos[1] = temp;
}
if(returns[0].returned->dist[pos[1]] > returns[0].returned->dist[pos[2]])
{
int temp = pos[1];
pos[1] = pos[2];
pos[2] = temp;
}
path_finder(returns[0].returned->prev,pos[0]);

if(returns[1].returned->dist[pos[1]] > returns[1].returned->dist[pos[2]])
{
int temp = pos[1];
pos[1] = pos[2];
pos[2] = pos[1];
}
path_finder(returns[1].returned->prev,pos[1]);
path_finder(returns[2].returned->prev,pos[2]);
path_finder(returns[3].returned->prev,dest);
}
else if(no_of_daimonds == 2)
{
if(returns[0].returned->dist[pos[0]] > returns[0].returned->dist[pos[1]])
{
path_finder(returns[0].returned->prev,pos[0]);
path_finder(returns[1].returned->prev,pos[1]);
}
}
else
{
path_finder(returns[0].returned->prev,pos[0]);
}

}
void path_finder(int *arr,int root1)
{
if(root1 != -1)
{
//printf("%d ",arr[root1]);
while(root1 != -1)
{
printf("<-%d ",arr[root1]);
root1 = arr[root1];
}
printf(" ->reached target\n");
return;
}
else
{
printf("at the target \n");
}
}
int main()
{
int src,dest,n1,n2;
int size;
printf("enter no of nodes : ");
scanf("%d",&size);
printf("diamond traveller problem : \n");
struct complete_node *graph = graph_designer(size);
printf("enter source : ");
scanf("%d",&src);
printf("enter destination : ");
scanf("%d",&dest);
printf("enter two nodes unreachable due to natural calamities : ");
scanf("%d%d",&n1,&n2);
knapSack(graph,size,src,dest,n1,n2);}


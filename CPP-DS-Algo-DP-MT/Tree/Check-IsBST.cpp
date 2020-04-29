//https://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/


// A C program to check for Identical BSTs without building the trees 
#include<stdio.h> 
#include<limits.h> 

  
/* The main function that checks if two arrays a[] and b[] of size n construct 
  same BST. The two values 'min' and 'max' decide whether the call is made for 
  left subtree or right subtree of a parent element. The indexes i1 and i2 are 
  the indexes in (a[] and b[]) after which we search the left or right child. 
  Initially, the call is made for INT_MIN and INT_MAX as 'min' and 'max' 
  respectively, because root has no parent. 
  i1 and i2 are just after the indexes of the parent element in a[] and b[]. */
bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2, int min, int max) 
{ 
   int j, k; 
  
   /* Search for a value satisfying the constraints of min and max in a[] and  
      b[]. If the parent element is a leaf node then there must be some  
      elements in a[] and b[] satisfying constraint. */
   for (j=i1; j<n; j++) 
       if (a[j]>min && a[j]<max) 
           break; 
   for (k=i2; k<n; k++) 
       if (b[k]>min && b[k]<max) 
           break; 
  
   /* If the parent element is leaf in both arrays */
   if (j==n && k==n) 
       return true; 
  
   /* Return false if any of the following is true 
      a) If the parent element is leaf in one array, but non-leaf in other. 
      b) The elements satisfying constraints are not same. We either search 
         for left child or right child of the parent element (decinded by min 
         and max values). The child found must be same in both arrays */
   if (((j==n)^(k==n)) || a[j]!=b[k]) 
       return false; 
  
   /* Make the current child as parent and recursively check for left and right 
      subtrees of it. Note that we can also pass a[k] in place of a[j] as they 
      are both are same */
   return isSameBSTUtil(a, b, n, j+1, k+1, a[j], max) &&  // Right Subtree 
          isSameBSTUtil(a, b, n, j+1, k+1, min, a[j]);    // Left Subtree 
} 
  
// A wrapper over isSameBSTUtil() 
bool isSameBST(int a[], int b[], int n) 
{ 
   return isSameBSTUtil(a, b, n, 0, 0, INT_MIN, INT_MAX); 
} 
  
// Driver program to test above functions 
int main() 
{ 
   int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13}; 
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13}; 
   int n=sizeof(a)/sizeof(a[0]); 
   printf("%s\n", isSameBST(a, b, n)? 
             "BSTs are same":"BSTs not same"); 
   return 0; 
} 

/*
https://ide.geeksforgeeks.org/fSHkIq			-	Wrong solution

https://www.geeksforgeeks.org/check-if-two-given-key-sequences-construct-same-bsts/?utm_source=feedburner&utm_medium=email&utm_campaign=Feed%3A+Geeksforgeeks+%28GeeksforGeeks%29

// A C program to check for Identical BSTs without building the trees
#include<stdio.h>
#include<limits.h>



bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2)
{
int j1, j2, k1, k2;
int tmpamn = 0, tmpamx = 0, tmpbmn = 0, tmpbmx =0;
for (j1=i1+1; j1<n; j1++)
{
	if (a[j1]>a[i1])
	{
		tmpamx = a[j1];
		break;
	}
}
for (j2=i1+1; j2<n; j2++)
{
	if (a[j2]<a[i1])
	{
		tmpamn = a[j2];
		break;
	}
}
for (k1=i2+1; k1<n; k1++)
{
	if (b[k1]<b[i2])
	{
		tmpbmn = b[k1];
		break;
	}
}
for (k2=i2+1; k2 < n; k2++)
{
    if(b[k2] > b[i2])
    {
        tmpbmx = b[k2];
        break;
    }
}
if(tmpamn == 0 && tmpbmn == 0 && tmpamx == 0 && tmpbmx == 0) return true;

if(tmpamn == tmpbmn && tmpamx == tmpbmx)
{
    return isSameBSTUtil(a, b, n, j1, k1) && // Right Subtree
		isSameBSTUtil(a, b, n, j2, k2) ; // Left Subtree
}
else
{
    false;
}

}

// A wrapper over isSameBSTUtil()
bool isSameBST(int a[], int b[], int n)
{
    return isSameBSTUtil(a, b, n, 0, 0);
}

// Driver program to test above functions
int main()
{
int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
int n=sizeof(a)/sizeof(a[0]);
printf("%s\n", isSameBST(a, b, n)?
			"BSTs are same":"BSTs not same");
return 0;
}


*/
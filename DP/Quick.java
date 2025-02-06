
public class Quick {

    public static void swap(int arr[],int a,int b)
    {
        int t=arr[a];
        arr[a]=arr[b];
        arr[b]=t;
    }

    public static int part(int arr[],int lb,int ub)
    {
        int start=lb;
        int end=ub;
        int pivot=arr[lb];
        while (start<end) 
        {
            while (arr[start]<=pivot && start<end) 
            {
                start++;
            }
            while (arr[end]>pivot) 
            {
                end--;    
            }
            if(start<end)
            {
                swap(arr,start,end);
            }
        }
        swap(arr,lb,end);
        return end;
    }


    public static void qs(int arr[],int lb,int ub)
    {
        if(lb<ub)
        {
            int pi= part(arr,lb,ub);
            qs(arr, lb, pi-1);
            qs(arr, pi+1, ub);

        }
    }
    public static void main(String[] args) {
        
        // int arr[]={3,2,1,1};
        int arr[]={9,8,7,6,5,4,3,2,1};
        qs(arr,0,arr.length-1);
        for(int x: arr)
        {
            System.out.print(x+" ");
        }
    }
}
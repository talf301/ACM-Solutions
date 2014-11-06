import java.util.Scanner;
import java.util.PriorityQueue;
public class f {
	public static boolean contained(int n, String s)
	{
		String p = "" + n;
		if(p.length() > s.length())
			return false;
		for(int i = 0; i < s.length() - p.length()+1; i++)
		{
			boolean found = true;
			for(int j = 0; j < p.length(); j++)
			{
				if(s.charAt(i+j) != p.charAt(j))
				{
					found = false;
					break;
				}
			}
			if(found)
				return true;
		}
		return false;
	}
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int m = Integer.parseInt(s.nextLine());
		for(int t = 1; t <= m; t++)
		{
			int k,w;
			String line = s.nextLine();
			k = Integer.parseInt(line.split(" ")[0]);
			w = Integer.parseInt(line.split(" ")[1]);
			String[] signs = new String[k];
			for(int i = 0; i < k; i++)
			{
				signs[i] = s.nextLine();
			}
			int complete = 0;
			PriorityQueue<Integer> winds = new PriorityQueue<Integer>();
			for(int i = 0; i < k; i++)
			{
				for(int p = 0; p < w; p++)
				{
					System.err.println(winds.peek() + ", " + (complete + p + 1) + ", " + complete);
					if(contained(complete+p+1, signs[i]))
					{
						//wind[p] = true;
						winds.add(complete+p+1);
					}
					int counter = 0;
					for(int j = 0; j < w; j++)
					{
						/*if(!wind[j])
							break;*/
						if(winds.isEmpty() || winds.peek() != complete+j+1)
							break;
						counter++;
						while(!winds.isEmpty() && winds.peek() == complete+j+1)
							winds.poll();
					}
					if(counter > 0)
					{
						complete += counter;
						p = -1;
					}
				}
				
			}
		
			int max = complete;
			/*for(int i = w-1; i >= 0; i--)
			{
				if(wind[i])
				{
					max = i+1+complete;
					break;
				}
			}*/
			while(true)
			{
				if(winds.isEmpty())
					break;
				
				max = winds.poll();
				//System.err.println(max);
			}
			System.out.println("Case " + t + ": " + complete + " " + max);
			
		} // HALP
		//System.err.println(contained(3, "13", 0));
	}
}

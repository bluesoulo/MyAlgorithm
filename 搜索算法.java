import java.util.*;
public class HelloWorld { 
	public static void BreadthSearch(int start[][],int goal[][]){
		NineTable startNode = new NineTable(start);
		NineTable goalNode = new NineTable(goal);
		LinkedList<NineTable> close = new LinkedList<>();
		LinkedList<NineTable> open  = new LinkedList<>();
		open.add(startNode);
		while(!open.getFirst().is_goal(goal)){
			System.out.println(open.getFirst().toString());
			close.addLast(open.getFirst());
			NineTable [] tem1 =open.getFirst().get_result();
			for(int i = 0;i<tem1.length;i++){
				int j =0,k=close.size();
				for(; j<k;j++)
					if(close.get(j).isEqual(tem1[i]))
						break;
				if(j==k)
					open.addLast(tem1[i]);;
			}
			open.removeFirst();	
		}
		System.out.println(open.getFirst().toString());
		System.out.println("宽度优先算法OK");
	}
	public static void DeepthSearch(int start[][],int goal[][]){
		NineTable startNode = new NineTable(start);
		NineTable goalNode = new NineTable(goal);
		LinkedList<NineTable> close = new LinkedList<>();
		LinkedList<NineTable> open  = new LinkedList<>();
		open.add(startNode);
		while(!open.getFirst().is_goal(goal)){
			System.out.println(open.getFirst().toString());
			close.addLast(open.getFirst());
			NineTable [] tem1 =open.getFirst().get_result();
			open.removeFirst();
			for(int i = 0;i<tem1.length;i++){
				int j =0,k=close.size();
				for(; j<k;j++)
					if(close.get(j).isEqual(tem1[i]))
						break;
				if(j==k)
					open.addFirst(tem1[i]);
			}
		}
		System.out.println(open.getFirst().toString());
		System.out.println("深度优先算法OK");
	}
	public static void ThinkSearch(int start[][],int goal[][]){
		NineTableThinking startNode = new NineTableThinking(start);
		NineTableThinking goalNode = new NineTableThinking(goal);
		LinkedList<NineTableThinking> open = new LinkedList<>();
		LinkedList<NineTableThinking> close = new LinkedList<>();		
		startNode.setDeepth(1);
		startNode.setgoal(goal);
		startNode.setValues();
		open.addFirst(startNode);
		int min =getMin(open);
		NineTableThinking minNode = new NineTableThinking(open.get(min).getStart());
		System.out.println(open.get(min));
		for(int i=2;!minNode.is_goal(goal)&&open.size()!=0;i++){
			NineTable [] tem1 = minNode.get_result();
			NineTableThinking [] tem2 = new NineTableThinking[tem1.length];
			for(int k =0;k<tem1.length;k++){
				tem2[k] = new NineTableThinking(tem1[k].getStart());
				tem2[k].setDeepth(i);
				tem2[k].setValues();
				boolean b =true;
				for(int j=0;j<close.size()&&b;j++)
					if(close.get(j).isEqual(tem2[k]))
						b=false;
				for(int j=0;j<open.size()&&b;j++)
					if(open.get(j).isEqual(tem2[k]))
						b=false;
				if(b)
				open.addLast(tem2[k]);
			}
			close.addFirst(open.get(min));
			open.remove(min);
			min =getMin(open);
			minNode = new NineTableThinking(open.get(min).getStart());
			System.out.println(open.get(min));
		}
		System.out.println("启发式搜索ok");
	}
	public static int getMin(LinkedList<NineTableThinking> open){
		int min=0;
		for(int i=0;i<open.size();i++)
			if(open.get(min).getValues()>open.get(i).getValues())
				min = i;
		return min;
	}
	public static void main(String[] args) {
		Scanner input =new Scanner(System.in);		
		int start[][] =new int[3][3];
		int goal[][] =new int[3][3];
		System.out.println("请输入起始的9宫格数字，数字的范围是1~8，注意需要空余的位置输入-1即可");
		for(int i =0;i<start.length;i++)
			for(int j=0;j<3;j++)
				start[i][j] =input.nextInt();
		System.out.println("请输入目标的9宫格数字，数字的范围是1~8，注意需要空余的位置输入-1即可");
		for(int i =0;i<start.length;i++)
			for(int j=0;j<3;j++)
				goal[i][j] =input.nextInt();
		//BreadthSearch(start,goal);
		System.out.println("******************");
		//DeepthSearch(start,goal);
		//System.out.println("******************");
		ThinkSearch(start,goal);
	}
}
//2 8 3 1 -1 4 7 6 5
//1 2 3 -1 8 4 7 6 5
class NineTable{
	private int start[][];
	public NineTable(){
		start=new int[3][3];
	}
	public boolean isEqual(NineTable n){
		int goal[][]=n.getStart();
		for(int i = 0;i<start.length;i++)
			for(int j = 0;j<start[i].length;j++)
				if(start[i][j] != goal[i][j])
					return false;
		return true;
	}
	public NineTable(int start1[][]){
		start=new int[3][3];
		for(int i = 0;i<start1.length;i++)
			for(int j = 0;j<start1[i].length;j++)
				start[i][j] = start1[i][j];	
	}
	
	public int[][] getStart() {
		return start;
	}
	@Override
	public String toString() {
		String s ="";
		for(int i = 0;i<start.length;i++)
			for(int j = 0;j<start[i].length;j++)
				s = s +start[i][j]+" ";
		return s;
	}
	public void setStart(int start1[][]){
		int start[][]=new int[3][3];
		for(int i = 0;i<start1.length;i++)
			for(int j = 0;j<start1[i].length;j++)
				start[i][j] = start1[i][j];	
	}
	public boolean is_goal(int goal[][]){
		boolean b =true;
		for(int i = 0;i<start.length&&b==true;i++)
			for(int j = 0;j<start[i].length;j++)
				if(start[i][j] != goal[i][j])
					b = false;
		return b;
	}
	public NineTable[]get_result(){		
		int temx = 0,temy = 0;
		int next[][][] =null;
		for(int i = 0;i<start.length;i++)
			for(int j = 0;j<start[i].length;j++)
				if (start[i][j]==-1){
					temx = i;
					temy =j;
				}
		if(temx==1&&temy==1)
			next= new int [4][3][3];
		else if(temx==1||temy==1)
			next = new int [3][3][3];
		else
			next = new int [2][3][3];
		int [] temarray =new int[next.length*9];
		int record = 0,temvalue =0;
		if(temx-1>=0){
			for(int i =0;i<3;i++)
				for(int j =0;j<3;j++)
					temarray[i*3+j]=start[i][j];
			temvalue= temarray[temx*3+temy];
			temarray[temx*3+temy] = temarray[(temx-1)*3+temy];
			temarray[(temx-1)*3+temy] =temvalue;
			record = record +9;
		}
		if(temx+1<3){
			for(int i =0;i<3;i++)
				for(int j =0;j<3;j++)
					temarray[record+i*3+j]=start[i][j];
			temvalue= temarray[record+temx*3+temy];
			temarray[record+temx*3+temy] = temarray[record+(temx+1)*3+temy];
			temarray[record+(temx+1)*3+temy] =temvalue;
			record = record +9;
		}
		if(temy+1<3){
			for(int i =0;i<3;i++)
				for(int j =0;j<3;j++)
					temarray[record+i*3+j]=start[i][j];
			temvalue= temarray[record+temx*3+temy];
			temarray[record+temx*3+temy] = temarray[record+temx*3+temy+1];
			temarray[record+temx*3+temy+1] =temvalue;
			record = record +9;
		}
		if(temy-1>=0){
			for(int i =0;i<3;i++)
				for(int j =0;j<3;j++)
					temarray[record+i*3+j]=start[i][j];
			temvalue= temarray[record+temx*3+temy];
			temarray[record+temx*3+temy] = temarray[record+temx*3+temy-1];
			temarray[record+temx*3+temy-1] =temvalue;
			record = record +9;
		}
		for(int x = 0;x < next.length;x++)
			for(int y = 0;y<3;y++)
				for(int z =0;z<3;z++){
					next[x][y][z] = temarray[x*9+y*3+z];
				}					
		NineTable [] b =new NineTable[next.length];
		for(int i = 0;i<b.length;i++)
			b[i] =new NineTable(next[i]); //每一个元素都必须给予独立的构造才可以
		return b;
	}
}
class NineTableThinking extends NineTable{
	static int goal[][]=new int[3][3];
	private int values;
	private int deepth;
	public NineTableThinking(){
		super();
		values =0;
		deepth=0;
	}
	public void setgoal(int goal1[][]){
		for(int i = 0;i<goal.length;i++)
			for(int j = 0;j<goal[i].length;j++)
				goal[i][j]=goal1[i][j];
	}

	public NineTableThinking(int array[][]){
		super(array);
		values =0;
		deepth=0;
	}
	public void setDeepth(int deepth){
		this.deepth =deepth; 
	}
	public void setValues() {
		int [][]start1=super.getStart();
		for(int i = 0;i<start1.length;i++)
			for(int j = 0;j<start1[i].length;j++)
				if(start1[i][j]!=goal[i][j])
					values++;
		values =values + deepth;
	}
	public int getValues(){
		return values;
	}
}

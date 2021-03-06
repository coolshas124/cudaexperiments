#include <iostream>

using namespace std;

void edgesPrint (int vertexArray[], int neighbourArray[], int n, int m){ 

	for (int i=0; i<n-1; i++){
		for (int j = vertexArray[i]; j < vertexArray[i+1]; ++j){

				cout<<"e "<<i+1<<" "<<neighbourArray[j]<<endl;
				/* code */
		}
	}

	for (int j = vertexArray[n-1]; j < m; ++j)
	{
			cout<<"e "<<n<<" "<<neighbourArray[j]<<endl;
				/* code */
		
	}
}

int main(int argc, char const *argv[])
{
	/* code */
//	string a, b;
	int n, m;
	
//	cin>>a>>b>>n>>m;
	cin>>n>>m;
	cout<<n<<" "<<m<<endl;

	int *vertexArray = new int [n];
	int *neighbourArray = new int [m];

	for (int i = 0; i < n; ++i)
	{
		/* code */
		vertexArray[i]=m;
	}
	
	int NSlast = 0;
	int NSoffset = 0;
	int NSprev=0;
	
	
	for (int i=0; i<m; i++){
		int start, end;
		
//		char c;
		
		cin>>start>>end;
//		start++;
//		end++;
//		cout<<start<<" "<<end<<endl;
		
//		cout<<NSlast<<" "<<NSprev<<endl;
		
		for (int j=NSlast+1; j<start; j++){
			vertexArray[j-1]=NSoffset;
			
		}
		
		if (NSprev!=start){
			NSlast=start;
//			cout<<"Start-1 "<<NSlast<<endl;
			vertexArray[start-1]=NSoffset;
			NSprev=start;
		}
		
//		cout<<"Offset "<<NSoffset<<endl;
		neighbourArray[NSoffset]=end;
		NSoffset++;
		
//		cout<<i+1<<endl;
		
	}
	
//	cout<<"2";

//	int offset = 0;

//	int current = 0;
//	int mark = 1;

//	for (int i = 0; i < m; ++i)
//	{
//		/* code */
//		char c;
//		int start;
//		int end;

//		cin>>c>>start>>end;
////		
////		cin>>start>>end;
////		start++;
////		end++;

//		if (start!=mark){ 

//			if (start == mark+1 && vertexArray[mark-1]!=m){ 

//			}

//			else{

//				for (int j = mark; j<start; j++){ 
//					vertexArray[j-1]=offset;
//					// neighbourArray[offset]=0;
//					// offset++;
//				}
//			}
//			mark = start;

//		}

//		if (start==current){ 
//			neighbourArray[offset]=end;
//			offset++;
//		}

//		else { 
//			current = start;

//			vertexArray[current-1]=offset;

//			neighbourArray[offset]=end;
//			offset++;
//		}
//	}

	//edgesPrint(vertexArray, neighbourArray, n, m);

	
	int *graphDegree = new int [n+1];
	
	for (unsigned int i = 0; i < n+1; i += 1)
	{
		graphDegree[i]=0;
	}
	
	for (int i=0; i<n-1; i++){
		for (int j = vertexArray[i]; j < vertexArray[i+1]; ++j){
				graphDegree[i]++;
//				cout<<i+1<<"\t"<<neighbourArray[j]<<endl;
				graphDegree[neighbourArray[j]-1]++;
				/* code */
		}
	}

	for (int j = vertexArray[n-1]; j < m; ++j)
	{
			graphDegree[n-1]++;
//			cout<<n<<"\t"<<neighbourArray[j]<<endl;
			graphDegree[neighbourArray[j]-1]++;
				/* code */
	}	
	
	for (unsigned int i = 0; i < n; i += 1)
	{
		if (graphDegree[n]<graphDegree[i]){
			graphDegree[n]=graphDegree[i];
		}
	}
	
	
//	for (unsigned int i = 0; i < n+1; i += 1)
//	{
//		cout<<graphDegree[i]<<endl;
//	}

	cout<<graphDegree[n]<<endl;
	
	for (unsigned int i = 0; i < n; i += 1)
	{
		cout<<graphDegree[i]<<endl;
	}

	for (int i=0; i<n-1; i++){
		for (int j = vertexArray[i]; j < vertexArray[i+1]; ++j){
//				graphDegree[i]++;
				cout<<i+1<<"\t"<<neighbourArray[j]<<endl;
//				graphDegree[neighbourArray[j]-1]++;
				/* code */
		}
	}

	for (int j = vertexArray[n-1]; j < m; ++j)
	{
//			graphDegree[n-1]++;
			cout<<n<<"\t"<<neighbourArray[j]<<endl;
//			graphDegree[neighbourArray[j]-1]++;
				/* code */
	}	
	
	return 0;
}

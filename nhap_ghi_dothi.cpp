 #include<stdio.h>
#include<conio.h>
#include<vector>
#include<string.h>
#include<iostream>

#include <stack>
#include <queue>

using namespace std;
struct thanhpho
{
	char ten[256];
	int loai;
	vector<int> vTo;
};
void nhapdothi(vector<thanhpho> &a)
{
	a.clear();
	char c;
	while(1)
	{
		c=getch();
		if(c==27)
		  break;
		thanhpho x;
		printf("Nhap ten thanh pho:");fflush(stdin);gets(x.ten);
		printf("Nhap loai:");scanf("%d",&x.loai);
		a.push_back(x);
	}
	for(int i=0;i<a.size();i++)
	{
		printf("Thanh pho %s noi toi\n",a[i].ten);
		while(1)
		{
			c=getch();
			if(c==27)
			  break;
			int x;
			printf("Chi so thanh pho:");
			scanf("%d",&x);
			printf("%s\n",a[x].ten);
			a[i].vTo.push_back(x);
		}
	}
}
void hienthi(vector<thanhpho> a)
{
	for(int i=0;i<a.size();i++)
	{
		printf("ten:%s\n loai:%i\n",a[i].ten,a[i].loai);
		if(a[i].vTo.size()==0)
		  printf("Khong co thanh pho co chuyen bay toi\n");
		else
		{
			for(int j=0;j<a[i].vTo.size();j++)
			   printf("ten:%s\n",a[a[i].vTo[j]].ten);
		}
	}
}
bool tim_thanhpho(char *tenthanhpho,vector<thanhpho> a)
{
	bool bok=false;
	for(int i=0;i<a.size();i++)
	{
		if(strcmp(a[i].ten,tenthanhpho)==0)
		{
			bok=true;
			if(a[i].vTo.size()>0)
			{
				printf("Cac thanh pho co chuyen bay truc tiep toi la:\n");
				for(int j=0;j<a[i].vTo.size();j++)
				{
					int index=a[i].vTo[j];
					printf("%s\n",a[index].ten);
				}
			}
			break;
		}
	}
	return bok;
}
void ghidothi(vector<thanhpho> a,char* tenfile)
{
	FILE *fp=fopen("dothi.txt","w+t");
	if(fp==NULL)
	  return;
	for(int i=0;i<a.size();i++)
	{
		fprintf(fp,"%s %d\n",a[i].ten,a[i].loai);
		if(a[i].vTo.size()==0)
		  fprintf(fp,"0\n");
		else
		{
			fprintf(fp,"%d\n",a[i].vTo.size());
			for(int j=0;j<a[i].vTo.size();j++)
			{
				int index=a[i].vTo[j];
				fprintf(fp,"%d %s\n",index,a[index].ten);
			}
		}
	}
	fclose(fp);
	fp=NULL;
}

bool DuyetTimPath_chieusau(int iBegin,int iEnd, vector<thanhpho> a)
{
	// Lam tr hop de nhat
	for(int i=0; i <a[iBegin].vTo.size();i++)
	{
		if(iEnd==a[iBegin].vTo[i])
			return true;// co canh noi tu iBegin den iEnd
	}//for
	
	stack<int> stack_node_trunggian;
	stack_node_trunggian.push(iBegin);
	
	while(stack_node_trunggian.empty()==false)
	{
		//doc dinh
		int iTrunggian=stack_node_trunggian.top();
		if(a[iTrunggian].vTo.size()==0) // trung gian ko co noi canh toi dau ca
			stack_node_trunggian.pop();
		else
		{
			// kiem t1ra tat ca cac dinh thuoc vTo, co dinh trung voi iEnd thi return true
			for(int i=0; i <a[iTrunggian].vTo.size();i++)
			{
				if(iEnd==a[iTrunggian].vTo[i])
					return true;// co canh noi tu iBegin den iEnd
			}//for
			
			// ko co phai di tiepo de co 1 node trung gian khac co the noi toi iEnd
			for(int i=0; i <a[iTrunggian].vTo.size();i++)
				stack_node_trunggian.push(a[iTrunggian].vTo[i]);// nap tat ca vTo vao stack
		}//else
	}// while
	
	// stack_node_trunggian empty va ko thay
	return false;
	
}// DuyetTimPath_chieusau

bool DuyetTimPath_chieurong(int iBegin,int iEnd, vector<thanhpho> a)
{
	// Lam tr hop de nhat
	for(int i=0; i <a[iBegin].vTo.size();i++)
	{
		if(iEnd==a[iBegin].vTo[i])
			return true;// co canh noi tu iBegin den iEnd
	}//for
	
	queue<int> queue_node_trunggian;
	
	queue_node_trunggian.push(iBegin);
	
	while(queue_node_trunggian.empty()==false)
	{
		// fornt: doc phan tu dau tien hang doi, pop la xoa phan tu dau tien khoi hang doi 
		int iTrunggian=queue_node_trunggian.front();
		queue_node_trunggian.pop();
		for(int i=0; i <a[iBegin].vTo.size();i++)
		{
			if(iEnd==a[iBegin].vTo[i])
				return true;// co canh noi tu iBegin den iEnd
		}//for
		
		// ko co phai di tiepo de co 1 node trung gian khac co the noi toi iEnd
		// nap ca 1 hang nh node noi toi vao hang doi
		for(int i=0; i <a[iTrunggian].vTo.size();i++)
			queue_node_trunggian.push(a[iTrunggian].vTo[i]);// nap tat ca vTo vao queue
		}//else
	}// while
	
	// queue_node_trunggian empty va ko thay
	return false;
	
}// DuyetTimPath_chieurong	

int main()
{
	vector<thanhpho> a;
	nhapdothi(a);
	hienthi(a);
	/*char sz[256];
	printf("Cho ten:");fflush(stdin);gets(sz);
	bool kq=tim_thanhpho(sz,a);
	if(kq==true)
		printf("tim thay ten thanh pho trong do thi\n");
	else
		printf("khong tim thay ten thanh pho trong do thi");
	ghidothi(a,"ghifile.txt");*/
	
	// thu ham
	int iBegin, iEnd;
	printf("nhap chi so thanh pho nguon:");
	scanf("%d",&iBegin);
	printf("nhap chi so thanh pho dich:");
	scanf("%d",&iEnd);
	if(DuyetTimPath_chieusau(iBegin,iEnd,a)==true)
		printf("from %s to %s co chuyen bay truc tiep hoac gian tiep\n",a[iBegin].ten,a[iEnd].ten);
	else
		printf("khong co chuyen bay gian tiep from %s to %s\n",a[iBegin].ten,a[iEnd].ten);
		
	if(DuyetTimPath_chieurong(iBegin,iEnd,a)==true)
		printf("from %s to %s co chuyen bay truc tiep hoac gian tiep\n",a[iBegin].ten,a[iEnd].ten);
	else
		printf("khong co chuyen bay gian tiep from %s to %s\n",a[iBegin].ten,a[iEnd].ten);
}

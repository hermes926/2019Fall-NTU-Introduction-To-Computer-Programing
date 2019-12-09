#include<stdio.h>
#include "stationDistance.h"

int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[]){
	int distance=0;int d=0;
	switch(startStation[0]){
		case 0:
			switch(endStation[0]){
				case 0:
					if(startStation[1]>endStation[1]){
						for(int c=endStation[1]-1;c<startStation[1]-1;c++){distance+=R_distance[c];}}
					else{
						for(int c=startStation[1]-1;c<endStation[1]-1;c++){distance+=R_distance[c];}}
					break;
				case 1:
					for(int c=0;c<endStation[1]-1;c++){distance+=G_distance[c];}
					if(startStation[1]>G_origin){
						for(int c=G_origin-1;c<startStation[1]-1;c++){distance+=R_distance[c];}}
					else{
						for(int c=startStation[1]-1;c<G_origin-1;c++){distance+=R_distance[c];}}
					break;
				default:
					d=0;
					while(G_distance[d]!=0){distance+=G_distance[d];d++;}
					if(startStation[1]>G_origin){
						for(int c=G_origin-1;c<startStation[1]-1;c++){distance+=R_distance[c];}}
					else{
						for(int c=startStation[1]-1;c<G_origin-1;c++){distance+=R_distance[c];}}
					if(endStation[1]>G_destination){
						for(int c=G_destination-1;c<endStation[1]-1;c++){distance+=B_distance[c];}}
					else{
						for(int c=endStation[1]-1;c<G_destination-1;c++){distance+=B_distance[c];}}
					break;		
			}
			break;
		
		case 1:
			switch(endStation[0]){
				case 0:
					for(int c=0;c<startStation[1]-1;c++){distance+=G_distance[c];}
					if(endStation[1]>G_origin){
						for(int c=G_origin-1;c<endStation[1]-1;c++){distance+=R_distance[c];}}
					else{
						for(int c=endStation[1]-1;c<G_origin-1;c++){distance+=R_distance[c];}}
					break;
				case 1:
					if(startStation[1]>endStation[1]){
						for(int c=endStation[1]-1;c<startStation[1]-1;c++){distance+=G_distance[c];}}
					else{
						for(int c=startStation[1]-1;c<endStation[1]-1;c++){distance+=G_distance[c];}}
					break;
				default:
					if(endStation[1]>G_destination){
						for(int c=G_destination-1;c<endStation[1]-1;c++){distance+=B_distance[c];}}
					else{
						for(int c=endStation[1]-1;c<G_destination-1;c++){distance+=B_distance[c];}}
					d=startStation[1]-1;
					while(G_distance[d]!=0){distance+=G_distance[d];d++;}
					break;		
			}
			break;
		case 2:
			switch(endStation[0]){
				case 0:
					d=0;
					while(G_distance[d]!=0){distance+=G_distance[d];d++;}
					if(endStation[1]>G_origin){
						for(int c=G_origin-1;c<endStation[1]-1;c++){distance+=R_distance[c];}}
					else{
						for(int c=endStation[1]-1;c<G_origin-1;c++){distance+=R_distance[c];}}
					if(startStation[1]>G_destination){
						for(int c=G_destination-1;c<startStation[1]-1;c++){distance+=B_distance[c];}}
					else{
						for(int c=startStation[1]-1;c<G_destination-1;c++){distance+=B_distance[c];}}
					break;
				case 1:
					if(startStation[1]>G_destination){
						for(int c=G_destination-1;c<startStation[1]-1;c++){distance+=B_distance[c];}}
					else{
						for(int c=startStation[1]-1;c<G_destination-1;c++){distance+=B_distance[c];}}
					d=endStation[1]-1;
					while(G_distance[d]!=0){distance+=G_distance[d];d++;}
					break;
				default:
					if(startStation[1]>endStation[1]){
						for(int c=endStation[1]-1;c<startStation[1]-1;c++){distance+=B_distance[c];}}
					else{
						for(int c=startStation[1]-1;c<endStation[1]-1;c++){distance+=B_distance[c];}}
					break;				
			}
			break;
	}
	
	
	
	return distance;	
}

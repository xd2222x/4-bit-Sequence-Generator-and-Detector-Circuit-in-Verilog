module seven_segment(clk,e,f,g,h,a,b,c,d,i,j,k,l,out_led,i1,j1,k1,l1,out1);
	input wire clk,e,f,g,h;
	output reg a,b,c,d,i,j,k,l,out_led; 
	output reg i1,j1,k1,l1,out1;  
	reg [28:0] delay;
	reg [3:0] bits;
	reg [15:0] rand_num;
	wire feedback;

	initial begin
		
		a=1;
		b=1;
		c=1;
		d=1;
		bits=4'b0000;
		//temp=4'd0;
		rand_num=16'd15;
		out_led=0;
		
	end
	
	always@(posedge clk)
	begin
		delay=delay+1;
		if(delay==29'b10001111000011010001100000000) //3 seconds delay
		begin
			delay=29'b0;
			
			//sending data from arduino
			a=e;
			b=f;
			c=g;
			d=h;
			
			//generating random bits
			
			feedback = rand_num[15] ^ rand_num[14] ^ rand_num[12] ^ rand_num[3];
			rand_num={rand_num[14:0], feedback};
			bits[0]=rand_num[0]; 
			
			
			feedback = rand_num[15] ^ rand_num[14] ^ rand_num[12] ^ rand_num[3];
			rand_num={rand_num[14:0], feedback};
			bits[1]=rand_num[0]; 
			
			feedback = rand_num[15] ^ rand_num[14] ^ rand_num[12] ^ rand_num[3];
			rand_num={rand_num[14:0], feedback};
			bits[2]=rand_num[0]; 
			
			
			feedback = rand_num[15] ^ rand_num[14] ^ rand_num[12] ^ rand_num[3];
			rand_num={rand_num[14:0], feedback};
			bits[3]=rand_num[0]; 
			
			
			
			i=bits[0];
			j=bits[1];
			k=bits[2];
			l=bits[3];
			
			
			//Going into lcd display
			i1=bits[0];
			j1=bits[1];
			k1=bits[2];
			l1=bits[3];
			
			
			//comparing bits for detecting sequence
			
			if(a==i && b==j && c==k && d==l)
			begin
				out_led=1;
				out1=1;
			end
			else
			begin
				out_led=0;
				out1=0;
			end
			
			
		end		
	end
endmodule 


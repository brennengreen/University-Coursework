module arbiter(input Clock, input Resetn, input w, output z);
    reg [3:1]y, Y;
    parameter [3:1] A=3'b000, B=3'b001, C=3b'010, D=3b'011, E=3b'100, F=3b'101, G=3b'110, H=3b'111
    always @(w or y)
        case(y)
            A: if (w) 
                Y = B; z= 0;
            else
                Y = A; z = 0;
            B: if (w)
                Y = C; z = 0;
            else 
                Y = E; z =0;
            C: if (w)
                Y = D; z = 0;
            else 
                Y = E; z= 0;
            D: if (w)
                Y = D; z = 1;
            else
                Y = E; z = 0;
            E: if (w)
            
            else
                Y = F; z = 0;
            F: if(w)
                Y = B; z = 1;
            else
                Y = A; z = 0;
            default: Y = 3'bxxx; z= 0;
        endcase
    always @(negedge Resetn or posedge Clock)
        if (Resetn == 0)
            y <= A;
        else 
            y <= Y;
endmodule
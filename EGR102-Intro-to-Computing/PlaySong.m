% Your header comment goes here

%%% Arduino configuration: change these lines as necessary
%Connect_Arduino();

%%% Your program goes here. Variable a is your Arduino object.

% Frequencies of musical notes, in Hz.
c = 261;
d = 294;
e = 329;
f = 349;
g = 391;
gS = 415;
a = 440;
aS = 455;
b = 466;
cH = 523;
cSH = 554;
dH = 587;
dSH = 622;
eH = 659;
fH = 698;
fSH = 740;
gH = 784;
gSH = 830;
aH = 880;
Rest = 0;

% Durations of musical notes, in seconds.
Whole = 0.6;
Half = Whole / 2;
Quarter = Whole / 4;

% The song to play.  Column 1 is the note, column 2 the duration. 
Section1 = [
        a, 500; ...
        a, 500; ... 
        a, 500; ...
        f, 350; ...
        cH, 150; ...  
        a, 500; ...
        f, 350; ...
        cH, 150; ...
        a, 650;
 ]; 

 Section1_5 = [
    eH, 500; ...
    eH, 500; ...
    eH, 500; ...
    fH, 350; ...
    cH, 150; ...
    gS, 500; ...
    f, 350;  ...
    cH, 150; ...
    a, 650;  ...
 ];

 Section2 = [
     
 ];

 Section2_5 = [
     
 ];

 Variant_1 = [
     
 ];


while true
    if readDigitalPin(a, 'D2')
        for idx = 1 : length(Song) % number of rows
            playTone(a, 'D9', Song(idx, 1), Song(idx, 2));
            % Wait until the note is over before starting the next one.
            pause(Song(idx, 2));
        end
    end
end

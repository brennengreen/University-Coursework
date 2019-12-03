% Your header comment goes here

%%% Arduino configuration: change these lines as necessary
Connect_Arduino();

%%% Your program goes here. Variable a is your Arduino object.

% Frequencies of musical notes, in Hz.
C = 262;
E = 330;
G = 392;
Rest = 0;

% Durations of musical notes, in seconds.
Whole = 0.6;
Half = Whole / 2;
Quarter = Whole / 4;

% The song to play.  Column 1 is the note, column 2 the duration. 
Song = [ C,     Quarter; ...
         G,     Half; ...
         E,     Quarter; ...
         Rest,  Quarter; ...
         C * 2, Half; ...    % Multiplying by two goes up an octave
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

unit UnitDemoMain;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,JoystickEx,
  StdCtrls, ExtCtrls,mmsystem;

type
  TForm1 = class(TForm)
    ScrollBar1: TScrollBar;
    Label1: TLabel;
    Panel1: TPanel;
    Label2: TLabel;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    LabelCal: TLabel;
    Joystickex1: TJoystickex;
    Button8: TButton;
    RGPort: TRadioGroup;
    procedure FormDestroy(Sender: TObject);
    procedure Joystickex1Button(Sender: TObject; Number: Byte;
      Pushed: Boolean);
    procedure ScrollBar1Change(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Joystickex1Button1_Change(Sender: TObject; pressed: Boolean;XPos,YPos : Integer);
    procedure Joystickex1Button2_Change(Sender: TObject; pressed: Boolean;XPos,YPos : Integer);
    procedure Joystickex1Button3_Change(Sender: TObject; pressed: Boolean;XPos,YPos : Integer);
    procedure Joystickex1Button4_Change(Sender: TObject; pressed: Boolean;XPos,YPos : Integer);
    procedure Joystickex1JoyMove(Sender: TObject; XPos, YPos: Integer; ButtonStatus: Word;IsCalibrating : Boolean);
    procedure Joystickex1JoyZMove(Sender: TObject; ZPos: Integer;ButtonStatus: Word;isCalibrating :Boolean);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure RGPortClick(Sender: TObject);
  private
    { Private-Deklarationen }
  public
    { Public-Deklarationen }
  end;

var
  Form1: TForm1;
  Joystick :TJoystickex;

implementation

{$R *.DFM}

procedure TForm1.FormDestroy(Sender: TObject);
begin
Joystick.Free;
end;

procedure TForm1.Joystickex1Button(Sender: TObject; Number: Byte;
  Pushed: Boolean);
begin
Form1.Caption := 'Button :'+IntToStr(Number);
end;

procedure TForm1.ScrollBar1Change(Sender: TObject);
begin
Panel1.Caption := floatToStr(Scrollbar1.Position/100);
Joystickex1.EventThreshold := Scrollbar1.Position/100;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
if not Joystickex1.EnableJoyStick then
   ShowMessage('Could not find a joystick') ;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
Joystickex1.disableJoystick ;
end;

procedure TForm1.Joystickex1Button1_Change(Sender: TObject;
  pressed: Boolean; XPos,YPos : Integer);
begin
if pressed then color := clred else color :=clBtnFace;
end;

procedure TForm1.Joystickex1Button2_Change(Sender: TObject;
  pressed: Boolean;XPos,YPos : Integer);
begin
if pressed then color := clgreen else color :=clBtnFace;
end;

procedure TForm1.Joystickex1Button3_Change(Sender: TObject;
  pressed: Boolean;XPos,YPos : Integer);
begin
if pressed then color := clblue else color :=clBtnFace;
end;

procedure TForm1.Joystickex1Button4_Change(Sender: TObject;
  pressed: Boolean;XPos,YPos : Integer);
begin
if pressed then color := clYellow else color :=clBtnFace;
end;

procedure TForm1.Joystickex1JoyMove(Sender: TObject; XPos, YPos: Integer; ButtonStatus: Word; Iscalibrating :Boolean);
begin
Form1.Caption := 'X : '+IntToStr(Xpos)+'/ Y : ' +IntToStr(Ypos)+ ' Buttons : ' + IntToStr(ButtonStatus);
application.ProcessMessages;
if IsCalibrating then Labelcal. Caption := 'Calibrating' else Labelcal. Caption := '';
SetCursorPos(xpos+Joystickex1.XScaledby,Ypos+Joystickex1.YScaledBy);

end;

procedure TForm1.Joystickex1JoyZMove(Sender: TObject; ZPos: Integer;
  ButtonStatus: Word;isCalibrating :Boolean);
begin
//Form1.Caption := 'Z : '+IntToStr(Zpos)+' / Buttons : ' + IntToStr(ButtonStatus);
//if IsCalibrating then Labelcal. Caption := 'Calibrating' else Labelcal. Caption := '';
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
if not Joystickex1.CalibrateCenter then ShowMessage('Could not calibrate center');
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
ShowMessage ('Leave joystick '+ IntToStr(Ord(Joystickex1.GamePort)+1)+ ' in the centerposition! Then press the OK- button...');

Joystickex1.CalibrateCenter;

if not Joystickex1.BeginCalibrateRange then
   Begin
   ShowMessage('Could not calibrate range');
   Exit;
   end;

ShowMessage('Now move this joystick in each direction to it`s extreams. Then press OK!');
Joystickex1.StopCalibrateRange;

end;

procedure TForm1.Button5Click(Sender: TObject);
begin
Joystickex1.StopCalibrateRange;
Button5.Enabled := False;
Button4.Enabled := True;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
Joystickex1.scaled := not  Joystickex1.Scaled;
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
Joystickex1.Polling := not Joystickex1.polling;
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
Joystickex1.SysDialog;

end;

procedure TForm1.RGPortClick(Sender: TObject);
begin
Joystickex1.disableJoystick ;
Joystickex1.GamePort:= TGameport(RGPort.ItemIndex);
if not Joystickex1.EnableJoyStick then
   ShowMessage('Could not find a joystick') ;
end;

end.

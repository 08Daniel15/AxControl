class Interpolator
{

    public:
        
        Interpolator(double vMax, double aMax, double ts);
        double InterpolationStep();
        double Command(double startPos, double endPos);
        void DebugValues();
        bool JobDone();

        // Interpolator Ausgabe
        double sollPos;
        double sollVel;
        double sollAcc;


    private:
        double c_ts;
        double c_vMax;
        double c_aMax;
        double c_startPos;
        double c_endPos;
        double c_deltaPos;
        double c_timeAcc;
        double c_s_Acc;
        double c_s_Con;
        double c_time_Con;
        int c_state;
        double sollPos_0;

        // Counts
        int c_z_Acc;    
        int c_z_Con;
        int c_ticks = 0;

        // Control
        unsigned char mode = 0;
        bool jobDone = false;

        void DetermineValues(double startPos, double endPos);
};

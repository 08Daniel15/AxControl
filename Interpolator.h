class Interpolator
{

    public:
        
        Interpolator(double vMax, double aMax, double ts);
        void DetermineValues(double startPos, double endPos);
        double InterpolationStep();

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
        double c_timeAcc = 0.0;
        double c_s_Acc;
        double c_s_Con;
        double c_time_Con;
        int c_state;

        // Counts
        int c_z_Acc;    
        int c_z_Con;
        int c_ticks;
};

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace McPC
{
    [StructLayout(LayoutKind.Sequential)]
    public class CPP_Q
    {
        public float w;
        public float x;
        public float y;
        public float z;
    };
    public enum HWV_T
    {
        HWv1,
        HWv2Left,
        HWv2Right,
        HWv3Left,
        HWv3Right,
        HWv3SingleNode,
        HWv3Knee2Nodes,
    };

    public enum SkeletonType
    {
        RightHand,
        LeftHand,
        RightHandArm,
        LeftHandArm,
        BothHandArm,
        BothHand,
        Body,
    };
    // the enum actually means the postion(index) of a specific bone in array of Node or Joints
    // but it's kept being named as 'type' to keep the code read easily.
    // the name to be modified after function stable
    public enum BoneType
    {
        Palm,
        Thumb_1,
        Thumb_2,
        Thumb_3,
        Index_1,
        Index_2,
        Index_3,
        Middle_1,
        Middle_2,
        Middle_3,
        Ring_1,
        Ring_2,
        Ring_3,
        Little_1,
        Little_2,
        Little_3,
        ForeArm,
        MiddleArm,
        UpperArm,
        // every modifition of this struct must modify initBoneType(), !!!!
        BoneAmount,
    };

    public partial class Form1 : Form
    {
        // no dynamic path because DllImport requires a constant value
        // so when GloveLibDll is built, output dll will be copied to bin/Debug or bin/Release of this project
        private const string DllFilePath = @"GloveLibDllCsharp.dll";

        [DllImport(DllFilePath, CallingConvention = CallingConvention.Cdecl)]
        private extern static IntPtr mc_newInstance(HWV_T hwVer, SkeletonType m);

        [DllImport(DllFilePath, CallingConvention = CallingConvention.Cdecl)]
        private extern static void mc_AddTestData();
        [DllImport(DllFilePath, CallingConvention = CallingConvention.Cdecl)]
        private extern static CPP_Q mc_GetQuat(IntPtr pMC, BoneType joint); // float[w,x,y,z]

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            IntPtr inst = mc_newInstance(HWV_T.HWv3Right, SkeletonType.RightHand);

            const int JOINT_COUNT = 19; //tmp here
            float[] qarr = new float[4]; //quaternion is always 4 numbers
            for (int n = 0; n < 102; n++)
            {
                mc_AddTestData();
                for (int i = 0; i < JOINT_COUNT; i++)
                {
                    // first parameter must be 0 for Right hand!! no test data for left hand 
                    // second parameter is joint index, ref GloveLibDll -> Header Files -> Definitions.h
                    CPP_Q q = mc_GetQuat(inst, BoneType.ForeArm);
                    //Marshal.Copy(qptr, qarr, 0, qarr.Length);
                    Console.WriteLine("joint" + i + ", w = " + q.w + ", x = " + q.x + ", y = " + q.y + ", z = " + q.z);
                }
            }
        }
    }
}

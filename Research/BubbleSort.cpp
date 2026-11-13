   template<typename Cont> void BubbleSort(Cont& v)
   {
      bool bSwaped = true;

      while(bSwaped)
      {
         bSwaped = false;
         for (size_t j = v.size() - 1; j > 0; j--)
         {
            if (v[j] < v[j - 1])
            {
               swap(v[j], v[j - 1]);
               bSwaped = true;
            }
         }
      }
   }

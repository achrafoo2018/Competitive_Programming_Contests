   ll l, r;
    cin  l  r;
    ll pw = pt(r);
    ll ans1 = r - pow(2, pw) + 1;
    ll ans2 = pow(2, pw) - pow(2, pw - 1);
    ll mx = max(ans1 * 1LL, ans2 * 1LL);
    ll ans3 = ((r - l + 1) % 2) ? ((r - l + 1) / 2 + 1) : ((r - l + 1) / 2);
    mx = max(mx, ans3 * 1LL);
    cout  (r - l + 1) - mx  endl;
 
ll pt(ll n)
{
    ll cnt = -1;
    while (n != 0)
    {
        n /= 2;
        cnt++;
    }
    return cnt;
}
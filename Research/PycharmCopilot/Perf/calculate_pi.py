from decimal import Decimal, localcontext
from time import perf_counter


PLACES = 1000
COUNT = 1000


def arctan_reciprocal(value: int) -> Decimal:
    """Calculate arctan(1 / value) using its alternating power series."""
    with localcontext() as context:
        context.prec = PLACES + 25
        x = Decimal(1) / value
        x_squared = x * x
        term = x
        total = term
        denominator = 3
        sign = -1
        threshold = Decimal(1).scaleb(-(PLACES + 20))

        while True:
            term *= x_squared
            addition = term / denominator
            if addition < threshold:
                return +total
            total += sign * addition
            sign = -sign
            denominator += 2


def calculate_pi() -> Decimal:
    """Calculate pi to the configured number of decimal places."""
    with localcontext() as context:
        context.prec = PLACES + 25
        return 16 * arctan_reciprocal(5) - 4 * arctan_reciprocal(239)


def main() -> None:
    call_times = []

    for call_number in range(1, COUNT+1):
        start = perf_counter()
        pi = calculate_pi()
        elapsed = perf_counter() - start
        call_times.append(elapsed)

        print(f"Call {call_number:2}: {elapsed:.6f} seconds")

    print(f"\nPI: {pi:.{PLACES}f}")
    print(
        f"Bottom line: total={sum(call_times):.6f}s, "
        f"average={sum(call_times) / len(call_times):.6f}s, "
        f"min={min(call_times):.6f}s, max={max(call_times):.6f}s"
    )


if __name__ == "__main__":
    main()
